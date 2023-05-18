
#ifndef LandladordsSERVICE_HPP
#define LandladordsSERVICE_HPP

#include "db/BookingDb.hpp"
#include "dto/PageDto.hpp"
#include "dto/StatusDto.hpp"

#include "oatpp/web/protocol/http/Http.hpp"
#include "oatpp/core/macro/component.hpp"

class   LandlordsService {
private:
    typedef oatpp::web::protocol::http::Status Status;
private:
    OATPP_COMPONENT(std::shared_ptr<BookingDb>, m_database); // Inject database component
public:

    oatpp::Object<LandlordsDto> createLandlord(const oatpp::Object<LandlordsDto>& dto);
    oatpp::Object<LandlordsDto> updateLandlord(const oatpp::Object<LandlordsDto>& dto);
    oatpp::Object<LandlordsDto> getLandlordById(const oatpp::String& id);
    oatpp::Object<PageDto<oatpp::Object<LandlordsDto>>> getAllLandlords(const oatpp::UInt32& offset, const oatpp::UInt32& limit);
    oatpp::Object<StatusDto> deleteLandlordById(const oatpp::String& id);

};

#endif
