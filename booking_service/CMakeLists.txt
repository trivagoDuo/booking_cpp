cmake_minimum_required(VERSION 3.1)

set(project_name booking_cpp) ## rename your project here

project(${project_name})

set(CMAKE_CXX_STANDARD 11)

add_library(${project_name}-lib
        src/controller/TenantController.hpp
        src/controller/LandlordController.hpp
        src/controller/PropertyController.hpp
        src/db/BookingDb.hpp
        src/dto/conf/ConfigDto.hpp
        src/dto/conf/PageDto.hpp
        src/dto/conf/StatusDto.hpp
        src/dto/TenantsDto.hpp
        src/dto/LandlordsDto.hpp
        src/dto/PropertysDto.hpp
        src/dto/BookingsDto.hpp
        src/service/TenantsService.cpp
        src/service/TenantsService.hpp
        src/service/LandlordsService.cpp
        src/service/LandlordsService.hpp
        src/service/PropertysService.hpp
        src/service/PropertysService.cpp
        src/AppComponent.hpp
        src/DatabaseComponent.hpp
        src/ErrorHandler.cpp
        src/ErrorHandler.hpp
        src/ServiceComponent.hpp
        src/SwaggerComponent.hpp
        )

target_include_directories(${project_name}-lib PUBLIC src)

## link libs

find_package(oatpp              1.3.0 REQUIRED)
find_package(oatpp-swagger      1.3.0 REQUIRED)
find_package(oatpp-postgresql   1.3.0 REQUIRED)

target_link_libraries(${project_name}-lib
        PUBLIC oatpp::oatpp
        PUBLIC oatpp::oatpp-test
        PUBLIC oatpp::oatpp-swagger
        PUBLIC oatpp::oatpp-postgresql
        )

add_definitions(
        # Path to swagger-ui resources #
        -DOATPP_SWAGGER_RES_PATH="${oatpp-swagger_INCLUDE_DIRS}/../bin/oatpp-swagger/res"

        # Path to config file #
        -DCONFIG_PATH="resources/config.json"

        ## Path to database migration scripts
        -DDATABASE_MIGRATIONS="sql"
)

#################################################################
## add executables

add_executable(${project_name}-exe
        src/App.cpp
        )
target_link_libraries(${project_name}-exe ${project_name}-lib)
add_dependencies(${project_name}-exe ${project_name}-lib)

add_executable(${project_name}-test
        test/Tests.cpp
        )
target_link_libraries(${project_name}-test ${project_name}-lib)
add_dependencies(${project_name}-test ${project_name}-lib)

enable_testing()
add_test(project-tests ${project_name}-test)