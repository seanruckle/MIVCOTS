
#include <iostream>
#include "splitter.hpp"
#include "serial/serial.h"

// TODO this is currently a test program

int main(){
    // #,<ID>,ST,<# satellites>,LT,<lattitude>,LG,<longitude>,AG,<age>,AL,<altitude>,CS,<course>,MH,<mph>,DT,<date>,TM,<time>,XA,<x accel>,YA,<y accel>,ZA,<z accel>,TP,<temp>,XG,<x gyro>,YG,<y gyro>,ZG,<z gyro>
    // basic test
    std::string test = "#,3,ST,6,LT,10333,LG,8444,AG,23000,AL,99999,CS,7900,MH,25,DT,081117,TM,06233333,XA,16353,YA,16333,ZA,8111,TP,24,XG,333,YG,444,ZG,555";
    // update test
    std::string test1 = "#,4,ST,6,LT,10334,LG,8444,AG,23000,AL,99999,CS,7900,MH,25,DT,081117,TM,06233333,XA,16353,YA,16333,ZA,8111,TP,24,XG,888,YG,777,ZG,666";
    // Missing fields test
    std::string test2 = "#,5,ST,,LT,,,8454,AG,23000,AL,99999,CS,7900,MH,25,DT,081117,TM,06233333,XA,16353,YA,16333,ZA,8111,TP,24,XG,888,YG,777,ZG,666";
    // Missing fields test 2
    std::string test3 = "#,5,LT,8454,AG,23000,AL,99999,CS,7900,MH,25,DT,081117,TM,06233333,XA,16353,YA,16333,ZA,8111,TP,24,XG,888,YG,777,ZG,666";
    // Uneven number of missing fields test
    std::string test4 = "#,6,ST,6,LT,,8454,AG,23000,AL,99999,CS,7900,MH,25,DT,081117,TM,06233333,XA,16353,YA,16333,ZA,8111,TP,24,XG,888,YG,777,ZG,666";

    //serial::Serial testSer("/dev/ttyACM0", 9600, serial::Timeout::simpleTimeout(1000));
    //std::cout<<testSer.isOpen()<<std::endl;


    splitter aSplitter;
    aSplitter.initialize("dataformat.conf");
    aSplitter.printLatest();

    aSplitter.parseString(test1);
    aSplitter.printLatest();

    // aSplitter.parseString(test2);
    // aSplitter.printLatest();

    // aSplitter.parseString(test3);
    // aSplitter.printLatest();

    // //aSplitter.parseString(test4);
    // aSplitter.printLatest();

    // // re - initialize test
    // std::string test5 = "#,7,ST,7,NONSENSE,99";
    // aSplitter.initialize(test5);
    // aSplitter.printLatest();
}
