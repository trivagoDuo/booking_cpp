
#ifndef TenantsController_hpp
#define TenantsController_hpp

#include "service/TenantsService.hpp"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen


class TenantsController : public oatpp::web::server::api::ApiController {
public:
    TenantsController(const std::shared_ptr<ObjectMapper>& objectMapper)
    : oatpp::web::server::api::ApiController(objectMapper)
  {}
private:
    TenantsService mTenatsService; // Create user service.
public:

  static std::shared_ptr<TenantsController> createShared(
    OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper) // Inject objectMapper component here as default parameter
  ){
    return std::make_shared<TenantsController>(objectMapper);
  }
  
  ENDPOINT_INFO(createTenant) {
    info->summary = "Create new Tenant";

    info->addConsumes<Object<TenantsDto>>("application/json");

    info->addResponse<Object<TenantsDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
  }
  ENDPOINT("POST", "tenants", createTenant,
           BODY_DTO(Object<TenantsDto>, tenantDto))
  {
    return createDtoResponse(Status::CODE_200, mTenatsService.createTenant(tenantDto));
  }
  
  
  ENDPOINT_INFO(putTenant) {
    info->summary = "Update Tenant by tenantId";

    info->addConsumes<Object<TenantsDto>>("application/json");

    info->addResponse<Object<TenantsDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

    info->pathParams["TenantId"].description = "Tenant Identifier";
  }
  ENDPOINT("PUT", "tenants/{tenantId}", putTenant,
           PATH(String, tenantId),
           BODY_DTO(Object<TenantsDto>, tenantDto))
  {
      tenantDto->id = tenantId;
    return createDtoResponse(Status::CODE_200, mTenatsService.updateTenant(tenantDto));
  }
  
  
  ENDPOINT_INFO(getTenantById) {
    info->summary = "Get one Tenant by tenantId";

    info->addResponse<Object<TenantsDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

    info->pathParams["tenantId"].description = "Tenant Identifier";
  }
  ENDPOINT("GET", "tenants/{tenantId}", getTenantById,
           PATH(String, userId))
  {
    return createDtoResponse(Status::CODE_200, mTenatsService.getTenantById(userId));
  }
  
  
  ENDPOINT_INFO(getTenants) {
    info->summary = "get all stored tenants";

    info->addResponse<oatpp::Object<UsersPageDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
  }
  ENDPOINT("GET", "tenants/offset/{offset}/limit/{limit}", getTenants,
           PATH(UInt32, offset),
           PATH(UInt32, limit))
  {
    return createDtoResponse(Status::CODE_200, mTenatsService.getAllTenants(offset, limit));
  }
  
  
  ENDPOINT_INFO(deleteTenant) {
    info->summary = "Delete Tenant by userId";

    info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

    info->pathParams["tenantId"].description = "User Identifier";
  }
  ENDPOINT("DELETE", "tenants/{tenantId}", deleteTenant,
           PATH(String, tenantId))
  {
    return createDtoResponse(Status::CODE_200, mTenatsService.deleteTenantById(tenantId));
  }

};

#include OATPP_CODEGEN_BEGIN(ApiController) //<- End Codegen

#endif /* UserController_hpp */
