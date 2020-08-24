#include <recipe/recipe_repository.h>

#include <algorithm>

namespace tabetai2::core::recipe {

using namespace ingredient;

std::optional<Recipe> RecipeRepository::find_by_id(int id) const {
    return m_database->get(id);
}

std::optional<Recipe> RecipeRepository::find_by_name(const std::string& name) const {
    auto recipes = m_database->get_all();

    for (auto& recipe : recipes) {
        if (recipe.name() == name) {
            return recipe;
        }
    }

    return {};
}

std::optional<std::vector<Recipe>> RecipeRepository::find_by_ingredients(
        const std::vector<Ingredient>& ingredients) const {
    auto recipes = m_database->get_all();

    std::vector<Recipe> recipes_found;
    std::copy_if(recipes.cbegin(), recipes.cend(), std::back_inserter(recipes_found), [&](const auto &r) {
        const auto &recipe_ingredients = r.ingredients();
        return std::all_of(recipe_ingredients.cbegin(), recipe_ingredients.cend(), [&](const auto &i) {
            std::find(ingredients.cbegin(), ingredients.cend(), i) != std::end(ingredients);
        });
    });

    if (recipes_found.empty()) {
        return {};
    }

    return recipes;
}

}
