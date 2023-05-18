
#ifndef LandlordController_hpp
#define LandlordController_hpp

#include "service/LandlordsService.hpp"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen


class LandlordController : public oatpp::web::server::api::ApiController {
public:
    LandlordController(const std::shared_ptr<ObjectMapper>& objectMapper)
            : oatpp::web::server::api::ApiController(objectMapper)
    {}
private:
    LandlordsService mLandlordsService; // Create user service.
public:

    static std::shared_ptr<LandlordController> createShared(
            OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper) // Inject objectMapper component here as default parameter
    ){
        return std::make_shared<LandlordController>(objectMapper);
    }

    ENDPOINT_INFO(createLandlador) {
        info->summary = "Create new Landlord";

        info->addConsumes<Object<LandlordsDto>>("application/json");

        info->addResponse<Object<LandlordsDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
    }
    ENDPOINT("POST", "Landlords", createLandlador,
             BODY_DTO(Object<LandlordsDto>, landlordDto))
    {
        return createDtoResponse(Status::CODE_200, mLandlordsService.createLandlord(landlordDto));
    }


    ENDPOINT_INFO(putLandlord) {
        info->summary = "Update Landlord by tenantId";

        info->addConsumes<Object<LandlordsDto>>("application/json");

        info->addResponse<Object<LandlordsDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

        info->pathParams["LandlordId"].description = "Landlord Identifier";
    }
    ENDPOINT("PUT", "landlords/{landlordId}", putLandlord,
             PATH(String, landlordId),
             BODY_DTO(Object<LandlordsDto>, landlordDto))
    {
        landlordDto->id = landlordId;
        return createDtoResponse(Status::CODE_200, mLandlordsService.updateLandlord(landlordDto));
    }


    ENDPOINT_INFO(getLandlordById) {
        info->summary = "Get one Landlord by tenantId";

        info->addResponse<Object<LandlordsDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

        info->pathParams["landlordId"].description = "Landlords Identifier";
    }
    ENDPOINT("GET", "landlords/{landlordId}", getLandlordById,
             PATH(String, landlordId))
    {
        return createDtoResponse(Status::CODE_200, mLandlordsService.getLandlordById(landlordId));
    }


    ENDPOINT_INFO(getLandlords) {
        info->summary = "get all stored landlords";

        info->addResponse<oatpp::Object<UsersPageDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
    }
    ENDPOINT("GET", "landlor/offset/{offset}/limit/{limit}", getLandlords,
             PATH(UInt32, offset),
             PATH(UInt32, limit))
    {
        return createDtoResponse(Status::CODE_200, mLandlordsService.getAllLandlords(offset, limit));
    }


    ENDPOINT_INFO(deleteLandlord) {
        info->summary = "Delete Landlord by landlordId";

        info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

        info->pathParams["landlordId"].description = "Landlord Identifier";
    }
    ENDPOINT("DELETE", "landlords/{landlordId}", deleteLandlord,
             PATH(String, landlordId))
    {
        return createDtoResponse(Status::CODE_200, mLandlordsService.deleteLandlordById(landlordId));
    }

};

#include OATPP_CODEGEN_BEGIN(ApiController) //<- End Codegen

#endif
