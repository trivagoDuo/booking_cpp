
#ifndef PropertyController_hpp
#define PropertyController_hpp

#include "service/PropertysService.hpp"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen


class PropertyController : public oatpp::web::server::api::ApiController {
public:
    PropertyController(const std::shared_ptr<ObjectMapper>& objectMapper)
            : oatpp::web::server::api::ApiController(objectMapper)
    {}
private:
   PropertysService mPropertyService; // Create user service.
public:

    static std::shared_ptr<PropertyController> createShared(
            OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper) // Inject objectMapper component here as default parameter
    ){
        return std::make_shared<PropertyController>(objectMapper);
    }

    ENDPOINT_INFO(createProperty) {
        info->summary = "Create new Property";

        info->addConsumes<Object<PropertysDto>>("application/json");

        info->addResponse<Object<PropertysDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
    }
    ENDPOINT("POST", "/property", createProperty,
             BODY_DTO(Object<PropertysDto>, propertyDto))
    {
        return createDtoResponse(Status::CODE_200, mPropertyService.createProperty(propertyDto));
    }


    ENDPOINT_INFO(putProperty) {
        info->summary = "Update Property by propertyId";

        info->addConsumes<Object<PropertysDto>>("application/json");

        info->addResponse<Object<PropertysDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

        info->pathParams["PropertyId"].description = "Property Identifier";
    }
    ENDPOINT("PUT", "propertys/{propertyId}", putProperty,
             PATH(String, propertyId),
             BODY_DTO(Object<PropertysDto>, propertyDto))
    {
        propertyDto->id = propertyId;
        return createDtoResponse(Status::CODE_200, mPropertyService.updateProperty(propertyDto));
    }


    ENDPOINT_INFO(getPropertyById) {
        info->summary = "Get one Property by PropertyId";

        info->addResponse<Object<PropertysDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

        info->pathParams["propertyId"].description = "Property Identifier";
    }

    ENDPOINT("GET", "propertys/propertyId/{propertyId}", getPropertyById,
             PATH(String, propertyId))
    {
        return createDtoResponse(Status::CODE_200, mPropertyService.getPropertyById(propertyId));
    }

    ENDPOINT_INFO(getPropertyByLandlordId) {
        info->summary = "Get one Property by LadlordId";

        info->addResponse<Object<PropertysDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

        info->pathParams["landlordId"].description = "Landlords Identifier";
    }
    ENDPOINT("GET", "propertys/landlordId/{landlordId}", getPropertyByLandlordId,
             PATH(String, landlordId))
    {
        return createDtoResponse(Status::CODE_200, mPropertyService.getPropertyByLandlordId(landlordId));
    }

    ENDPOINT_INFO(getPropertyByAddress) {
        info->summary = "Get one Property by address";

        info->addResponse<Object<PropertysDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

        info->pathParams["address"].description = "address property";
    }
    ENDPOINT("GET", "propertys/address/{address}", getPropertyByAddress,
             PATH(String, address))
    {
        return createDtoResponse(Status::CODE_200, mPropertyService.getPropertyByAddreess(address));
    }

    ENDPOINT_INFO(getPropertyByCity) {
        info->summary = "Get one Property by City";

        info->addResponse<Object<PropertysDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

        info->pathParams["city"].description = "property";
    }
    ENDPOINT("GET", "propertys/city/{city}", getPropertyByCity,
             PATH(String, city))
    {
        return createDtoResponse(Status::CODE_200, mPropertyService.getPropertyByCity(city));
    }

    ENDPOINT_INFO(getPropertyByState) {
        info->summary = "Get one Property by State";

        info->addResponse<Object<PropertysDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

        info->pathParams["state"].description = "state property";
    }
    ENDPOINT("GET", "propertys/state/{state}", getPropertyByState,
             PATH(String, state))
    {
        return createDtoResponse(Status::CODE_200, mPropertyService.getPropertyByState(state));
    }

    ENDPOINT_INFO(getPropertyByPrice) {
        info->summary = "Get one Property by price";

        info->addResponse<Object<PropertysDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

        info->pathParams["price"].description = "Price per month property";
    }
    ENDPOINT("GET", "propertys/price/{price}", getPropertyByPrice,
             PATH(Float64 , price))
    {
        return createDtoResponse(Status::CODE_200, mPropertyService.getPropertyByPrice(price));
    }




    ENDPOINT_INFO(getPropertys) {
        info->summary = "get all stored Propertys";

        info->addResponse<oatpp::Object<PropertysPageDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
    }
    ENDPOINT("GET", "propertys/offset/{offset}/limit/{limit}", getPropertys,
             PATH(UInt32, offset),
             PATH(UInt32, limit))
    {
        return createDtoResponse(Status::CODE_200, mPropertyService.getAllPropertys(offset, limit));
    }


    ENDPOINT_INFO(deleteProperty) {
        info->summary = "Delete Property by PropertyId";

        info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

        info->pathParams["propertyId"].description = "Property Identifier";
    }
    ENDPOINT("DELETE", "propertys/{propertyId}", deleteProperty,
             PATH(String, propertyId))
    {
        return createDtoResponse(Status::CODE_200, mPropertyService.deletePropertydById(propertyId));
    }

};

#include OATPP_CODEGEN_BEGIN(ApiController) //<- End Codegen

#endif
