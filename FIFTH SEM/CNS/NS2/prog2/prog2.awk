BEGIN {
    #include<stdio.h>
    pktDropsRtr1 = 0;
    pktDropsRtr2 = 0;
}
{
    if($1=="d") {
        if($3=="2") {pktDropsRtr1++;}
        if($3=="3") {pktDropsRtr2++;}
    }
}
END {
    printf("Number of packets dropped at router1: %d\n", pktDropsRtr1);
    printf("Number of packets dropped at router2: %d\n", pktDropsRtr2);

}