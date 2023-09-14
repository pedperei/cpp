#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    ICharacter* bob = new Character("bob");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    me->equip(tmp);
    me->use(1, *bob);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);
    me->unequip(3);
    delete tmp; //delete unequiped Materia
    tmp = src->createMateria("cure");
    me->equip(tmp);
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(3, *bob);
    Character asd;
    asd = Character((Character&)*me);
    asd.use(0, *bob);
    asd.use(1, *bob);
    asd.use(3, *bob);
    delete bob;
    delete me;
    delete src;
    return 0;
}