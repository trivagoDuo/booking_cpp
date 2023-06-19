
#include "BookingsService.hpp"

oatpp::Object<BookingsDto> BookingsService::createBooking(const oatpp::Object<BookingsDto>& dto) {

    auto Check = m_database->CheckBooking(dto->house_id, dto->start_date, dto->end_date);
    OATPP_ASSERT_HTTP(Check->isSuccess(), Status::CODE_500, Check->getErrorMessage());

    auto items = Check->fetch<oatpp::Vector<oatpp::Object<BookingsDto>>>();
    auto checsk = items->size() > 1;
    OATPP_ASSERT_HTTP(!checsk, Status::CODE_409 ,"date used already");

    auto dbResult = m_database->createBooking(dto);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());

    auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<BookingsDto>>>();
    OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
    return result[0];

}

oatpp::Object<BookingsDto> BookingsService::updateBooking(const oatpp::Object<BookingsDto> &dto) {

    auto dbResult = m_database->updateBooking(dto);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<BookingsDto>>>();
    OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
    return result[0];

}

oatpp::Object<BookingsDto> BookingsService::getBookingById(const oatpp::String &id) {

    auto dbResult = m_database->getBookingById(id);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "Booking not found");

    auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<BookingsDto>>>();
    OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");

    return result[0];

}

oatpp::Object<BookingsDto> BookingsService::getBookingByPropertyId(const oatpp::String &id) {

    auto dbResult = m_database->getBookingByPropertyId(id);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "Booking not found");

    auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<BookingsDto>>>();
    OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");

    return result[0];

}

oatpp::Object<BookingsDto> BookingsService::getBookingByTenantId(const oatpp::String &id) {

    auto dbResult = m_database->getBookingByTenatId(id);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "Booking not found");

    auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<BookingsDto>>>();
    OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");

    return result[0];

}
oatpp::Object<BookingsDto> BookingsService::getBookingsByLandlordId(const oatpp::String &id) {

    auto dbResult = m_database->getBookingByLandlordId(id);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "Booking not found");

    auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<BookingsDto>>>();
    OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");

    return result[0];

}
oatpp::Object<PageDto<oatpp::Object<BookingsDto>>> BookingsService::getAllBookings(const oatpp::UInt32& offset, const oatpp::UInt32& limit) {

    oatpp::UInt32 countToFetch = limit;

    if(limit > 10) {
        countToFetch = 10;
    }

    auto dbResult = m_database->getAllBookings(offset, countToFetch);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());

    auto items = dbResult->fetch<oatpp::Vector<oatpp::Object<BookingsDto>>>();

    auto page = PageDto<oatpp::Object<BookingsDto>>::createShared();
    page->offset = offset;
    page->limit = countToFetch;
    page->count = items->size();
    page->items = items;

    return page;

}

oatpp::Object<StatusDto> BookingsService::deleteBookingsById(const oatpp::String& id) {
    auto dbResult = m_database->deleteBookingById(id);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    auto status = StatusDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = "Bookings was successfully deleted";
    return status;
}