#ifndef PropertysDto_hpp
#define PropertysDto_hpp

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class PropertysDto : public oatpp::DTO {

    DTO_INIT(PropertysDto, DTO)
    DTO_FIELD(String, id);
    DTO_FIELD(String, landlord_id, "landlord_id");
    DTO_FIELD(String, address, "address");
    DTO_FIELD(String, city, "city");
    DTO_FIELD(String, state, "state");
    DTO_FIELD(String, country, "country");
    DTO_FIELD(String, zipcode, "zipcode");
    DTO_FIELD(Float64, price_per_month, "price_per_month");
    DTO_FIELD(String, image_url, "image_url");
    DTO_FIELD(String,announcement_text, "announcement_text");

};

#include OATPP_CODEGEN_END(DTO)
#endif

