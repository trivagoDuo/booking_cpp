
#ifndef BookingController_hpp
#define BookingController_hpp

#include "service/BookingsService.hpp"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen


class BookingController : public oatpp::web::server::api::ApiController {
public:
    BookingController(const std::shared_ptr<ObjectMapper>& objectMapper)
            : oatpp::web::server::api::ApiController(objectMapper)
    {}
private:
    BookingsService mBookingsService; // Create user service.
public:

    static std::shared_ptr<BookingController> createShared(
            OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper) // Inject objectMapper component here as default parameter
    ){
        return std::make_shared<BookingController>(objectMapper);
    }

    ENDPOINT_INFO(createBooking) {
        info->summary = "Create new Booking";

        info->addConsumes<Object<BookingsDto>>("application/json");

        info->addResponse<Object<BookingsDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
    }
    ENDPOINT("POST", "/bookings", createBooking,
             BODY_DTO(Object<BookingsDto>, bookingsDto))
    {
        return createDtoResponse(Status::CODE_200, mBookingsService.createBooking(bookingsDto));
    }


    ENDPOINT_INFO(putBooking) {
        info->summary = "Update Booking";

        info->addConsumes<Object<LandlordsDto>>("application/json");

        info->addResponse<Object<LandlordsDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

        info->pathParams["bookingId"].description = "booking Identifier";
    }
    ENDPOINT("PUT", "bookings/{bookingId}", putBooking,
             PATH(String, bookingId),
             BODY_DTO(Object<BookingsDto>, bookingsDto))
    {
        bookingsDto->id = bookingId;
        return createDtoResponse(Status::CODE_200, mBookingsService.updateBooking(bookingsDto));
    }


    ENDPOINT_INFO(getBookingById) {
        info->summary = "Get one booking by Booking Id";

        info->addResponse<Object<BookingsDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

        info->pathParams["bookingId"].description = "Bookings Identifier";
    }

    ENDPOINT("GET", "bookings/{bookingId}", getBookingById,
             PATH(String, bookingId))
    {
        return createDtoResponse(Status::CODE_200, mBookingsService.getBookingById(bookingId));
    }

    ENDPOINT_INFO(getBookingWithTenantId) {
        info->summary = "Get one Booking by tenantId";

        info->addResponse<Object<BookingsDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

        info->pathParams["tenantsId"].description = "Tenants Identifier";
    }
    ENDPOINT("GET", "bookings/tenant/{tenantsId}", getBookingWithTenantId,
             PATH(String, tenantsId))
    {
        return createDtoResponse(Status::CODE_200, mBookingsService.getBookingByTenantId(tenantsId));
    }

    ENDPOINT_INFO(getBookingWithPropertyId) {
        info->summary = "Get one Booking by propertyId";

        info->addResponse<Object<BookingsDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

        info->pathParams["propertyId"].description = "Propertys Identifier";
    }
    ENDPOINT("GET", "bookings/property/{propertyId}", getBookingWithPropertyId,
             PATH(String, propertyId))
    {
        return createDtoResponse(Status::CODE_200, mBookingsService.getBookingByPropertyId(propertyId));
    }
    ENDPOINT_INFO(getBookingWirhLandlordId) {
        info->summary = "Get one Booking by landlordId";

        info->addResponse<Object<BookingsDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

        info->pathParams["landlordId"].description = "Landlords Identifier";
    }
    ENDPOINT("GET", "bookings/landlord/{landlordId}", getBookingWirhLandlordId,
             PATH(String,landlordId))
    {
        return createDtoResponse(Status::CODE_200, mBookingsService.getBookingsByLandlordId(landlordId));
    }



    ENDPOINT_INFO(getBookings) {
        info->summary = "get all stored landlords";

        info->addResponse<oatpp::Object<TenantsDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
    }
    ENDPOINT("GET", "bookings/offset/{offset}/limit/{limit}", getBookings,
             PATH(UInt32, offset),
             PATH(UInt32, limit))
    {
        return createDtoResponse(Status::CODE_200, mBookingsService.getAllBookings(offset, limit));
    }


    ENDPOINT_INFO(deleteBooking) {
        info->summary = "Delete Booking by BookingId";

        info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

        info->pathParams["bookingId"].description = "Booking Identifier";
    }
    ENDPOINT("DELETE", "bookings/{bookingId}", deleteBooking,
             PATH(String, bookingId))
    {
        return createDtoResponse(Status::CODE_200, mBookingsService.deleteBookingsById(bookingId));
    }

};

#include OATPP_CODEGEN_BEGIN(ApiController) //<- End Codegen

#endif
