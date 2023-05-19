#ifndef PropertysSERVICE_HPP
#define PropertysSERVICE_HPP

#include "db/BookingDb.hpp"
#include "dto/conf/PageDto.hpp"
#include "dto/conf/StatusDto.hpp"

#include "oatpp/web/protocol/http/Http.hpp"
#include "oatpp/core/macro/component.hpp"

class   PropertysService {
private:
    typedef oatpp::web::protocol::http::Status Status;
private:
    OATPP_COMPONENT(std::shared_ptr<BookingDb>, m_database); // Inject database component
public:

    oatpp::Object<PropertysDto> createProperty(const oatpp::Object<PropertysDto>& dto);
    oatpp::Object<PropertysDto> updateProperty(const oatpp::Object<PropertysDto>& dto);
    oatpp::Object<PropertysDto> getPropertyById(const oatpp::String& id);
    oatpp::Object<PageDto<oatpp::Object<PropertysDto>>> getAllPropertys(const oatpp::UInt32& offset, const oatpp::UInt32& limit);
    oatpp::Object<StatusDto> deletePropertydById(const oatpp::String& id);

};

#endif