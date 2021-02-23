//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include "catch.hpp"
//------------------------------

// Use this enum class for indicating the lat/long direction
enum class Compass {N, S, W, E};

// Write your code here
class GPS {
private:
double latitude;
Compass latitudeDirection;
double longitude;
Compass longitudeDirection;

public:
double getLongtitude;
Compass getLatitudeDirection(); 
double getLatitude;
Compass getLongitudeDirection();

GPS(double a, double b) {
  if (((0.0 <= a) && (a <= 90.0)) && ((0.0 <= b) && (b <= 180.0))){
  latitude = a;
  longitude = b;
  latitudeDirection = Compass::N;
  longitudeDirection = Compass::W;
  }
  else if (((0.0 > a) || (a > 90.0)) && ((0.0 <= b) && (b <= 180.0))) {
    latitude = 0;
    latitudeDirection = Compass::N;
    longitude = b;
    longitudeDirection = Compass::W;
  }
  else if (((0.0 <= a) && (a <= 90.0)) && ((0.0 > b) || (b > 180.0))) {
    latitude = a;
    latitudeDirection = Compass::N;
    longitude = 0;
    longitudeDirection = Compass::W;
  }
  else if (((0.0 > a) || (a > 90.0)) && ((0.0 > b) || (b > 180.0))){
    latitude = 0;
    latitudeDirection = Compass::N;
    longitude = 0;
    longitudeDirection = Compass::W;
  }
}

GPS(){
  longitude = 0;
  latitude = 0;
  latitudeDirection = Compass::N;
  longitudeDirection = Compass::W;
}
GPS(double a, Compass c, double b, Compass d) {
  latitude = a;
  latitudeDirection = c;
  longitude = b;
  longitudeDirection = y;

  if (((0.0 <= a) && (a <= 90.0)) && ((0.0 <= b) && (b <= 180.0))){
    if (((c == Compass::N) || (c == Compass::S)) && ((d == Compass::W) || (d == Compass::E))){
      latitudeDirection = d;
      longitudeDirection = d;
    }
    else if (((c != Compass::N) && (c != Compass::S)) && ((d == Compass::W) || (d == Compass::E))){
      latitudeDirection = Compass::N;
      longitudeDirection = d;
    }
    else if (((c == Compass::N) || (c == Compass::S)) && ((d != Compass::W) && (d != Compass::E)));
    {
      latitudeDirection = c;
      longitudeDirection = Compass::W;
    }
  latitude = a;
  longitude = b;
  }

  else if (((0.0 > a) || (a > 90.0)) && ((0.0 <= b) && (b <= 180.0))) {
    latitude = 0;
    latitudeDirection = Compass::N;
    longitude = b;
    longitudeDirection = Compass::W;
  }

  else if (((0.0 <= a) && (a <= 90.0)) && ((0.0 > b) || (b > 180.0))) {
    latitude = a;
    latitudeDirection = Compass::N;
    longitude = 0;
    longitudeDirection = Compass::W;
  }
  
  else if (((0.0 > a) || (a > 90.0)) && ((0.0 > b) || (b > 180.0))){
    latitude = 0;
    latitudeDirection = Compass::N;
    longitude = 0;
    longitudeDirection = Compass::W;
  }
}

{return latitude };
{return latitudeDirection};

{return longitude };

{return longitudeDirection };

};

//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------

TEST_CASE( "GPS" ) {
    SECTION( "t1" ) {
        GPS c;
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 0.0 );
        REQUIRE( c.getLongitudeDirection() == Compass::W );
    }
    SECTION( "t2" ) {
        GPS c{12.12, 50.34};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 50.34 );
        REQUIRE( c.getLongitudeDirection() == Compass::W );
    }
    SECTION( "t3" ) {
        GPS c{12.12, Compass::S, 50.34, Compass::E};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLatitudeDirection() == Compass::S );
        REQUIRE( c.getLongitude() == 50.34 );
        REQUIRE( c.getLongitudeDirection() == Compass::E );
    }
    SECTION( "t4" ) {
        GPS c{122.12, 50.34};
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLongitude() == 50.34 );
    }
    SECTION( "t5" ) {
        GPS c{122.12, 500.34};
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLongitude() == 0.0 );
    }
    SECTION( "t6" ) {
        GPS c{-122.12, 50.34};
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLongitude() == 50.34 );
    }
    SECTION( "t7" ) {
        GPS c{12.12, -50.34};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLongitude() == 0.0 );
    }
    SECTION( "t8" ) {
        GPS c{12.12, Compass::W, 50.34, Compass::E};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 50.34 );
        REQUIRE( c.getLongitudeDirection() == Compass::E );
    }
    SECTION( "t9" ) {
        GPS c{12.12, Compass::N, 50.34, Compass::N};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 50.34 );
        REQUIRE( c.getLongitudeDirection() == Compass::W );
    }
    SECTION( "t10" ) {
        GPS c{-12.12, Compass::E, 540.34, Compass::N};
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 0.0 );
        REQUIRE( c.getLongitudeDirection() == Compass::W );
    }
}
//------------------------------
