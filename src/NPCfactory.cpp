#include "../include/NPC/NPCfactory.hpp"

std::shared_ptr<NPC> NPCFactory::createNPC(int x, int y, const std::string &name, const std::string &type)
{
    if (type == "Orc"){return std::make_shared<Orc>(x, y, name);}
    else if (type == "Druid"){return std::make_shared<Druid>(x, y, name);}
    else if (type == "SlaveTrader"){return std::make_shared<SlaveTrader>(x, y, name);}
    else{
        std::cerr << "Unknown NPC type: " << type << std::endl;
        return nullptr;
    }
}