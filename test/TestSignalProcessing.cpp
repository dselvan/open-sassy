#include "catch.hpp"
#include "../src/SignalProcessing.h"
#include <math.h>

TEST_CASE("Derivitives are computed", "[diff]")
{
    double signal_segment[5] = {1, 2, 3, 4, 5};
    double sampling_frequency = 2;

    REQUIRE(SignalProcessing::diff(signal_segment, sampling_frequency) == 2.0);

    SECTION("Sampling frequency is set to 0")
    {
        sampling_frequency = 0;
        REQUIRE(SignalProcessing::diff(signal_segment, sampling_frequency) == 1.0);
    }

    SECTION("Sampling frequency is set to less than 0")
    {
        sampling_frequency = -2;
        REQUIRE(SignalProcessing::diff(signal_segment, sampling_frequency) == 1.0);
    }

    SECTION("d/dx(cos(x)) = sin(x)")
    {
        double cos_segment[5] = {0.999992, 0.999998, 1, 0.999998, 0.999992};
        sampling_frequency = 500;

        REQUIRE(SignalProcessing::diff(cos_segment, sampling_frequency) == 0.0);
    }
}

TEST_CASE("Points converted to vector", "[points_to_vector]")
{
    volatile double mag = 0;
    volatile double dir = 0;

    int x[2] = {0, 1};
    int y[2] = {0, 1};

    SignalProcessing::points_to_vector(x[0], x[1], y[0], y[1], &mag, &dir);
    REQUIRE(mag == sqrt(2));
    REQUIRE(dir == 45);

    SECTION("Angle in the second quadrant")
    {
        int a[2] = {0, -1};
        int b[2] = {0, 1};

        SignalProcessing::points_to_vector(a[0], a[1], b[0], b[1], &mag, &dir);
        REQUIRE(mag == sqrt(2));
        REQUIRE(dir == 135);
    }

    SECTION("Angle in the third quadrant")
    {
        int a[2] = {0, -1};
        int b[2] = {0, -1};

        SignalProcessing::points_to_vector(a[0], a[1], b[0], b[1], &mag, &dir);
        REQUIRE(mag == sqrt(2));
        REQUIRE(dir == -135);
    }

    SECTION("Angle in the fourth quadrant")
    {
        int a[2] = {0, 1};
        int b[2] = {0, -1};

        SignalProcessing::points_to_vector(a[0], a[1], b[0], b[1], &mag, &dir);
        REQUIRE(mag == sqrt(2));
        REQUIRE(dir == -45);
    }

    SECTION("Same points give 0 magnitude and direction")
    {
        int a[2] = {3, 3};
        int b[2] = {4, 4};

        SignalProcessing::points_to_vector(a[0], a[1], b[0], b[1], &mag, &dir);
        REQUIRE(mag == 0);
        REQUIRE(dir == 0);
    }
}