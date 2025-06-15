cmake_minimum_required(VERSION 3.30)
project(HotelReservationSystemTester CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define diretórios base
set(PROJECT_HEADERS_DIR ../HotelReservationSystem/headers)
set(PROJECT_SOURCES_DIR ../HotelReservationSystem/sources)

# Configuração para Controladores
set(PROJECT_HEADERS_CONTROLLER_DIR ${PROJECT_HEADERS_DIR}/controller)
set(PROJECT_SOURCES_CONTROLLER_DIR ${PROJECT_SOURCES_DIR}/controller)
include_directories(${PROJECT_HEADERS_CONTROLLER_DIR})
set(CONTROLLER_SOURCE_FILES
        ${PROJECT_SOURCES_CONTROLLERS_DIR}/Controller.cpp
)

# Configuração para Dados
set(PROJECT_HEADERS_DATA_DIR ${PROJECT_HEADERS_DIR}/data)
set(PROJECT_SOURCES_DATA_DIR ${PROJECT_SOURCES_DIR}/data)
include_directories(${PROJECT_HEADERS_DATA_DIR})
set(DATA_SOURCE_FILES
        ${PROJECT_SOURCES_DATA_DIR}/seed.cpp
)

# Configuração para Exceções
set(PROJECT_HEADERS_EXCEPTIONS_DIR ${PROJECT_HEADERS_DIR}/exceptions)
set(PROJECT_SOURCES_EXCEPTIONS_DIR ${PROJECT_SOURCES_DIR}/exceptions)
include_directories(${PROJECT_HEADERS_EXCEPTIONS_DIR})
set(EXCEPTIONS_SOURCE_FILES
        ${PROJECT_SOURCES_EXCEPTIONS_DIR}/AccountAlreadyExistsException.cpp
        ${PROJECT_SOURCES_EXCEPTIONS_DIR}/ActivityUnavailableException.cpp
        ${PROJECT_SOURCES_EXCEPTIONS_DIR}/CancellationNotAllowedException.cpp
        ${PROJECT_SOURCES_EXCEPTIONS_DIR}/CouponInvalidException.cpp
        ${PROJECT_SOURCES_EXCEPTIONS_DIR}/InvalidCredentialsException.cpp
        ${PROJECT_SOURCES_EXCEPTIONS_DIR}/InvalidReservationDetailsException.cpp
        ${PROJECT_SOURCES_EXCEPTIONS_DIR}/PaymentFailedException.cpp
        ${PROJECT_SOURCES_EXCEPTIONS_DIR}/ReviewValidationException.cpp
        ${PROJECT_SOURCES_EXCEPTIONS_DIR}/RoomNotAvailableException.cpp
        ${PROJECT_SOURCES_EXCEPTIONS_DIR}/ServiceUnavailableException.cpp
)

# Configuração para o Utils
set(PROJECT_HEADERS_UTILS_DIR ${PROJECT_HEADERS_DIR}/utils)
set(PROJECT_SOURCES_UTILS_DIR ${PROJECT_SOURCES_DIR}/utils)
include_directories(${PROJECT_HEADERS_UTILS_DIR})

set(UTILS_SOURCE_FILES
        ${PROJECT_SOURCES_UTILS_DIR}/utils.cpp
)

# Configuração para o Modelo (Dados)
set(PROJECT_HEADERS_MODEL_DIR ${PROJECT_HEADERS_DIR}/model)
set(PROJECT_SOURCES_MODEL_DIR ${PROJECT_SOURCES_DIR}/model)
include_directories(${PROJECT_HEADERS_MODEL_DIR})
set(MODEL_SOURCE_FILES
        ${PROJECT_SOURCES_MODEL_DIR}/Activity.cpp
        ${PROJECT_SOURCES_MODEL_DIR}/ActivityContainer.cpp
        ${PROJECT_SOURCES_MODEL_DIR}/Cancellation.cpp
        ${PROJECT_SOURCES_MODEL_DIR}/Client.cpp
        ${PROJECT_SOURCES_MODEL_DIR}/Comment.cpp
        ${PROJECT_SOURCES_MODEL_DIR}/CommentContainer.cpp
        ${PROJECT_SOURCES_MODEL_DIR}/Coupon.cpp
        ${PROJECT_SOURCES_MODEL_DIR}/Date.cpp
        ${PROJECT_SOURCES_MODEL_DIR}/Hotel.cpp
        ${PROJECT_SOURCES_MODEL_DIR}/Payment.cpp
        ${PROJECT_SOURCES_MODEL_DIR}/Person.cpp
        ${PROJECT_SOURCES_MODEL_DIR}/Reservation.cpp
        ${PROJECT_SOURCES_MODEL_DIR}/ReservationContainer.cpp
        ${PROJECT_SOURCES_MODEL_DIR}/Room.cpp
        ${PROJECT_SOURCES_MODEL_DIR}/RoomContainer.cpp
        ${PROJECT_SOURCES_MODEL_DIR}/Service.cpp
        ${PROJECT_SOURCES_MODEL_DIR}/ServiceContainer.cpp
)

# Configuração para as Views
set(PROJECT_HEADERS_VIEWS_DIR ${PROJECT_HEADERS_DIR}/views)
set(PROJECT_SOURCES_VIEWS_DIR ${PROJECT_SOURCES_DIR}/views)
include_directories(${PROJECT_HEADERS_VIEWS_DIR})
set(VIEWS_SOURCE_FILES
        ${PROJECT_SOURCES_VIEWS_DIR}/AccountView.cpp
        ${PROJECT_SOURCES_VIEWS_DIR}/ActivityView.cpp
        ${PROJECT_SOURCES_VIEWS_DIR}/InformationView.cpp
        ${PROJECT_SOURCES_VIEWS_DIR}/MainView.cpp
        ${PROJECT_SOURCES_VIEWS_DIR}/PaymentView.cpp
        ${PROJECT_SOURCES_VIEWS_DIR}/ReviewView.cpp
        ${PROJECT_SOURCES_VIEWS_DIR}/RoomView.cpp
        ${PROJECT_SOURCES_VIEWS_DIR}/SearchView.cpp
        ${PROJECT_SOURCES_VIEWS_DIR}/ServiceView.cpp
)


set(GOOGLE_TEST_LIB ${PROJECT_SOURCE_DIR}/googleTestLib/googletest-main)
set(GOOGLE_TEST_LIB_INCLUDE ${GOOGLE_TEST_LIB}/googletest/include)

add_subdirectory(${GOOGLE_TEST_LIB})
include_directories(${GOOGLE_TEST_LIB_INCLUDE})

add_executable(HotelReservationSystemTester
        AccountAlreadyExistsException_tester.cpp
        AccountView_tester.cpp
        ActivitiesView_tester.cpp
        Activity_tester.cpp
        ActivityContainer_tester.cpp
        ActivityUnavailableException_tester.cpp
        Cancellation_tester.cpp
        CancellationNotAllowedException_tester.cpp
        Client_tester.cpp
        Comment_tester.cpp
        CommentContainer_tester.cpp
        Controller_tester.cpp
        Coupon_tester.cpp
        CouponInvalidException_tester.cpp
        Date_tester.cpp
        Hotel_tester.cpp
        InformationView_tester.cpp
        InvalidCredentialsException_tester.cpp
        InvalidReservationDetailsException_tester.cpp
        MainView_tester.cpp
        Payment_tester.cpp
        PaymentFailedException_tester.cpp
        PaymentView_tester.cpp
        Person_tester.cpp
        Reservation_tester.cpp
        ReservationContainer_tester.cpp
        ReviewValidationException_tester.cpp
        ReviewView_tester.cpp
        Room_tester.cpp
        RoomContainer_tester.cpp
        RoomNotAvailableException_tester.cpp
        RoomView_tester.cpp
        SearchView_tester.cpp
        seed_tester.cpp
        Service_tester.cpp
        ServiceContainer_tester.cpp
        ServiceUnavailableException_tester.cpp
        ServiceView_tester.cpp
        utils_tester.cpp

        ${APP_SOURCE_FILES}
        ${CONTROLLERS_SOURCE_FILES}
        ${EXCEPTIONS_SOURCE_FILES}
        ${MODEL_SOURCE_FILES}
        ${VIEWS_SOURCE_FILES}

)

target_sources(HotelReservationSystemTester PRIVATE
        ${APP_SOURCE_FILES}
)

target_link_libraries(HotelReservationSystemTester gtest gtest_main)