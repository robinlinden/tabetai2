#pragma once

#include <database/database.hpp>

#include "ingredient.h"

#include <memory>

namespace tabetai2::core::ingredient {

class IngredientRepository {
public:
    explicit IngredientRepository(std::unique_ptr<database::Database<Ingredient>> database);

    void add(const Ingredient& ingredient);
    void erase(const Ingredient& ingredient);

    std::optional<Ingredient> find_by_id(int id);
    std::optional<Ingredient> find_by_name(const std::string& name);

private:
    std::unique_ptr<database::Database<Ingredient>> m_database;
};

}