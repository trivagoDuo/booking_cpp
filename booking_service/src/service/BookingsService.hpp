
#ifndef BookingsSERVICE_HPP
#define BookingsSERVICE_HPP

#include "db/BookingDb.hpp"
#include "dto/conf/PageDto.hpp"
#include "dto/conf/StatusDto.hpp"

#include "oatpp/web/protocol/http/Http.hpp"
#include "oatpp/core/macro/component.hpp"

class   BookingsService {
private:
    typedef oatpp::web::protocol::http::Status Status;
private:
    OATPP_COMPONENT(std::shared_ptr<BookingDb>, m_database); // Inject database component
public:

    oatpp::Object<BookingsDto> createBooking(const oatpp::Object<BookingsDto>& dto);
    oatpp::Object<BookingsDto> updateBooking(const oatpp::Object<BookingsDto>& dto);
    oatpp::Object<BookingsDto> getBookingById(const oatpp::String& id);
    oatpp::Object<BookingsDto> getBookingsByLandlordId(const oatpp::String& id);
    oatpp::Object<BookingsDto> getBookingByPropertyId(const oatpp::String& id);
    oatpp::Object<BookingsDto> getBookingByTenantId(const oatpp::String& id);
    oatpp::Object<PageDto<oatpp::Object<BookingsDto>>> getAllBookings(const oatpp::UInt32& offset, const oatpp::UInt32& limit);
    oatpp::Object<StatusDto> deleteBookingsById(const oatpp::String& id);

};

#endif
