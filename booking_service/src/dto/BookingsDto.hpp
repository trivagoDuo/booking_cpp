#ifndef BookingsDto_hpp
#define BookingsDto_hpp

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)


class BookingsDto : public oatpp::DTO {

    DTO_INIT(BookingsDto, DTO)
    DTO_FIELD(String, id);
    DTO_FIELD(String, house_id, "house_id");
    DTO_FIELD(String, tenant_id, "tenant_id");
    DTO_FIELD(String, landlord_id, "landlord_id");
    DTO_FIELD(String, start_date, "start_date");
    DTO_FIELD(String, end_date, "end_date");
    DTO_FIELD(Float64 , total_cost, "total_cost");

};

#include OATPP_CODEGEN_END(DTO)

#endif
