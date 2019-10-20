#include "BulletsContainer.hpp"
#include "AEntity.hpp"

BulletContainer::BulletContainer() :
_screen(nullptr),
_bullets(nullptr) {
}

BulletContainer::BulletContainer(Screen *sc) :
_screen(sc),
_bullets(nullptr) {
}

BulletContainer::BulletContainer(BulletContainer const &src) {
    *this = src;
}

BulletContainer::~BulletContainer() {
    while (_bullets) {
        delBullet(0);
    }
}

BulletContainer &BulletContainer::operator=(BulletContainer const &rhs) {
    if (this != &rhs) {
        _bullets = getBullets();
    }
    return *this;
}

Bullet *BulletContainer::newBullet(int x, int y, int velX, int velY, uint64_t speedMs) {
    BulletContainer::BulletLst *tmp = _bullets;

    // create new bulletlst element
    BulletLst *new_ = new BulletLst();
    new_->bullet = new Bullet(_screen, x, y, velX, velY, speedMs);

    if (tmp) {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new_;
    }
    else {
        _bullets = new_;
    }
	return (new_->bullet);
}

void BulletContainer::delBullet(int idx) {
    BulletContainer::BulletLst *lastTmp = nullptr;
    BulletContainer::BulletLst *tmp = _bullets;

    if (_bullets == nullptr) {
        return;
    }
    if (idx == 0) {
        _bullets = _bullets->next;
        delete tmp->bullet;
        delete tmp;
        return;
    }

    int i = 0;
    while (tmp && i < idx) {
        i++;
        lastTmp = tmp;
        tmp = tmp->next;
    }
    if (tmp == nullptr) {
        return;
    }
    lastTmp->next = tmp->next;
    delete tmp->bullet;
    delete tmp;
}

void BulletContainer::update() {
    BulletContainer::BulletLst *lastTmp = nullptr;
    BulletContainer::BulletLst *tmp = _bullets;

    while (tmp) {
		this->getScreen()->deleteElement(*tmp->bullet);
        if (tmp->bullet->update() == false) {
            if (lastTmp == nullptr) {
                _bullets = tmp->next;
                lastTmp = _bullets;
                delete tmp->bullet;
                delete tmp;
                tmp = lastTmp;
                lastTmp = nullptr;
            }
            else {
                lastTmp->next = tmp->next;
                delete tmp->bullet;
                delete tmp;
                tmp = lastTmp->next;
            }
        }
        else {
			this->getScreen()->displayElement(*tmp->bullet);
            lastTmp = tmp;
            tmp = tmp->next;
        }
    }
}

BulletContainer::BulletLst *BulletContainer::getBullets() const { return _bullets; }

Bullet *BulletContainer::getBullet(int idx) const {
    BulletContainer::BulletLst *tmp = _bullets;
    int i = 0;
    while (tmp && i < idx) {
        i++;
        tmp = tmp->next;
    }
    return ((tmp == nullptr) ? nullptr : tmp->bullet);
}

Screen						*BulletContainer::getScreen() const
{
	return (this->_screen);
}

BulletContainer::BulletLst::BulletLst() : bullet(nullptr), next(nullptr) {}