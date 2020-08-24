#pragma once

#include <ingredient/ingredient.h>

#include <string>
#include <vector>

namespace tabetai2::core::recipe {

class Recipe {
public:
    Recipe(int id, std::string name, std::vector<ingredient::Ingredient> ingredients, std::vector<std::string> steps);

    int id() const;
    const std::string &name() const;
    const std::vector<ingredient::Ingredient> &ingredients() const;
    const std::vector<std::string> &steps() const;

private:
    const int m_id;
    const std::string m_name;
    const std::vector<ingredient::Ingredient> m_ingredients;
    const std::vector<std::string> m_steps;
};

}
