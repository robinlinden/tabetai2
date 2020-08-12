#include "server/server_factory.h"

#include "impl/server.h"

namespace tabetai2::core::server {

using namespace core::database;
using namespace core::ingredient;
using namespace core::server;

std::unique_ptr<Server> ServerFactory::create() const {
    auto ingredient_database = std::make_unique<Database<Ingredient>>();
    auto ingredient_repository = std::make_unique<IngredientRepository>(std::move(ingredient_database));

//    auto repository_publisher = std::make_unique<RepositoryPublisher>();
//    ingredient_repository->add_observer(repository_publisher);

    return std::make_unique<impl::Server>(std::move(ingredient_repository));
}

}
