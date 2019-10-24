#include "Brainfuck.hpp"
#include "AInstruction.hpp"
#include "IncrPtr.hpp"
#include "DecrPtr.hpp"
#include "IncrData.hpp"
#include "DecrData.hpp"
#include "CoutData.hpp"
#include "GetInput.hpp"
#include "WhileStart.hpp"
#include "WhileEnd.hpp"
#include <iostream>

Brainfuck::Brainfuck() :
_data(new std::string()),
_ptr(0),
_instrList(),
_prog(),
_progPtr(0) {
    _init();
}

Brainfuck::Brainfuck(Brainfuck const &src) {
    *this = src;
}

Brainfuck::~Brainfuck() {
    delete _data;
    for (std::map<char, AInstruction*>::iterator it=_instrList.begin(); it!=_instrList.end(); ++it)
        delete it->second;
}

Brainfuck &Brainfuck::operator=(Brainfuck const &rhs) {
    if (this != &rhs) {
        _data = new std::string(rhs.getData());
        _ptr = rhs.getPtr();
        _instrList = rhs.getInstrList();
        _prog = rhs.getProg();
    }
    return *this;
}

void Brainfuck::_init() {
    // create data str
    _data->reserve(MAX_STR_SIZE);

    AInstruction *instr;

    // create instr map
    instr = new IncrPtr(this);
    _instrList.insert(std::pair<char, AInstruction*>(instr->getInstr(), instr));
    instr = new DecrPtr(this);
    _instrList.insert(std::pair<char, AInstruction*>(instr->getInstr(), instr));
    instr = new IncrData(this);
    _instrList.insert(std::pair<char, AInstruction*>(instr->getInstr(), instr));
    instr = new DecrData(this);
    _instrList.insert(std::pair<char, AInstruction*>(instr->getInstr(), instr));
    instr = new CoutData(this);
    _instrList.insert(std::pair<char, AInstruction*>(instr->getInstr(), instr));
    instr = new GetInput(this);
    _instrList.insert(std::pair<char, AInstruction*>(instr->getInstr(), instr));
    instr = new WhileStart(this);
    _instrList.insert(std::pair<char, AInstruction*>(instr->getInstr(), instr));
    instr = new WhileEnd(this);
    _instrList.insert(std::pair<char, AInstruction*>(instr->getInstr(), instr));
}

bool Brainfuck::compile(std::string srcCode) {
    for (uint32_t i=0; i < srcCode.size(); i++) {
        char instrAct = srcCode[i];
        if (_instrList.find(instrAct) != _instrList.end()) {
            _prog.push_back(_instrList.find(instrAct)->second);
        }
        else {
            std::cout << "Invalid instruction: " << instrAct << " (char " << i << ")" << std::endl;
            return false;
        }
    }
    return true;
}

bool Brainfuck::decodePrgm() {
    AInstruction *instr;
    while (_progPtr < _prog.size()) {
        instr = _prog[_progPtr];
        // std::cout << "exec: " << instr->getInstr() << std::endl;
        if (instr->exec() == false) {
            std::cout << "Error in instruction: " << instr->getInstr() << std::endl;
            return false;
        }
        _progPtr++;
    }
    std::cout << std::endl;
    return true;
}


std::string const  &Brainfuck::getData() const { return *_data; }
std::string        &Brainfuck::getData() { return *_data; }
uint64_t           Brainfuck::getPtr() const { return _ptr; }
uint64_t           &Brainfuck::getPtr() { return _ptr; }
std::map<char, AInstruction*> const &Brainfuck::getInstrList() const { return _instrList; }
std::vector<AInstruction*> const    &Brainfuck::getProg() const { return _prog; }
uint64_t           Brainfuck::getProgPtr() const { return _progPtr; }
uint64_t           &Brainfuck::getProgPtr() { return _progPtr; }
