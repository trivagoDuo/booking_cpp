
#ifndef EXAMPLE_POSTGRESQL_PAGEDTO_HPP
#define EXAMPLE_POSTGRESQL_PAGEDTO_HPP

#include "dto/TenantsDto.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)"oatpp/codegen/DTO_define.hpp"

template<class T>
class PageDto : public oatpp::DTO {

  DTO_INIT(PageDto, DTO)

  DTO_FIELD(UInt32, offset);
  DTO_FIELD(UInt32, limit);
  DTO_FIELD(UInt32, count);
  DTO_FIELD(Vector<T>, items);

};

class TenantsPageDto : public PageDto<oatpp::Object<TenantsDto>> {

  DTO_INIT(TenantsPageDto, PageDto<oatpp::Object<TenantsDto>>)

};
class LandlordsPageDto : public PageDto<oatpp::Object<LandlordsDto>> {

    DTO_INIT(LandlordsPageDto, PageDto<oatpp::Object<LandlordsDto>>)

};

class BookingsPageDto : public PageDto<oatpp::Object<BookingsDto>> {

    DTO_INIT(BookingsPageDto, PageDto<oatpp::Object<BookingsDto>>)

};

class PropertysPageDto : public PageDto<oatpp::Object<PropertysDto>> {

    DTO_INIT(PropertysPageDto, PageDto<oatpp::Object<PropertysDto>>)

};

#include OATPP_CODEGEN_END(DTO)"oatpp/codegen/DTO_undef.hpp"

#endif
