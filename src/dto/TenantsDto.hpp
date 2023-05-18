
#define TenantsDto_hpp

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)


class TenantsDto : public oatpp::DTO {
  
  DTO_INIT(TenantsDto, DTO)
  DTO_FIELD(String, id);
  DTO_FIELD(String, username, "username");
  DTO_FIELD(String, email, "email");
  DTO_FIELD(String, password, "password");
  DTO_FIELD(String, name, "name");
  DTO_FIELD(String, phone, "phone");

};

#include OATPP_CODEGEN_END(DTO)

#endif /* UserDto_hpp */
