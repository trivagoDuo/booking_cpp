#ifndef UserDto_hpp
#define UserDto_hpp

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

ENUM(Role, v_int32,
        VALUE(GUEST, 0, "ROLE_USER"),
        VALUE(ADMIN, 2, "ROLE_ADMIN")
        VALUE(TENANT, 1, "ROLE_TENANT" )
)

class UserDto : public oatpp::DTO {

    DTO_INIT(UserDto, DTO)

    DTO_FIELD(String, id);
    DTO_FIELD(String, userName, "username");
    DTO_FIELD(String, email, "email");
    DTO_FIELD(String, password, "password");
    DTO_FIELD(Enum<Role>::AsString, role, "role");

};

#include OATPP_CODEGEN_END(DTO)

#endif /* UserDto_hpp */