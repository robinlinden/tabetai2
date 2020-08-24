#include <recipe/recipe.h>

#include <utility>

namespace tabetai2::core::recipe {

using namespace ingredient;

Recipe::Recipe(int id, std::string name, std::vector<Ingredient> ingredients, std::vector<std::string> steps)
: m_id(id),
  m_name(std::move(name)),
  m_ingredients(std::move(ingredients)),
  m_steps(std::move(steps)) {

}

int Recipe::id() const {
    return m_id;
}

const std::string &Recipe::name() const {
    return m_name;
}

const std::vector<ingredient::Ingredient> &Recipe::ingredients() const {
    return m_ingredients;
}

const std::vector<std::string> &Recipe::steps() const {
    return m_steps;
}

}
