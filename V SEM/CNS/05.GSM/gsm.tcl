set ns [new Simulator]
set tf [open 5.tr w]
$ns trace-all $tf

set topo [new Topography]
$topo load_flatgrid 1500 1500

set nf [open 5.nam w]
$ns namtrace-all-wireless $nf 1500 1500

$ns node-config -adhocRouting AODV \
                -llType LL \
                -macType Mac/802_11 \
                -ifqType Queue/DropTail/PriQueue \
                -ifqLen 1000 \
                -phyType Phy/WirelessPhy \
                -channelType Channel/WirelessChannel \
                -propType Propagation/TwoRayGround \
                -antType Antenna/OmniAntenna \
                -topoInstance $topo \
                -type GSM \
                -enegrgyModel EnergyModel \
                -initialEnegry 100 \
                -rxPower 0.3 \
                -txPower 0.6 \
                -agentTrace ON \
                -routerTrace ON \
                -macTrace OFF

create-god 10
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]
set n6 [$ns node]
set n7 [$ns node]
set n8 [$ns node]
set n9 [$ns node]

$n0 set X_ 1000
$n0 set Y_ 500
$n0 set Z_ 0

$n1 set X_ 600
$n1 set Y_ 300
$n1 set Z_ 0

$n2 set X_ 400
$n2 set Y_ 200
$n2 set Z_ 0

$n3 set X_ 700
$n3 set Y_ 250
$n3 set Z_ 0

$n4 set X_ 435
$n4 set Y_ 343
$n4 set Z_ 0

$n5 set X_ 452
$n5 set Y_ 234
$n5 set Z_ 0

$n6 set X_ 364
$n6 set Y_ 643
$n6 set Z_ 0

$n7 set X_ 635
$n7 set Y_ 234
$n7 set Z_ 0

$n8 set X_ 563
$n8 set Y_ 435
$n8 set Z_ 0

$n9 set X_ 234
$n9 set Y_ 324
$n9 set Z_ 0

set udp0 [new Agent/UDP]
$ns attach-agent $n2 $udp0
set sink [new Agent/LossMonitor]
$ns attach-agent $n3 $sink
set cbr0 [new Application/Traffic/CBR]
$cbr0 set packetSize_ 1000
$cbr0 set interval_ 0.1
$cbr0 set maxpkts_ 1000
$cbr0 attach-agent $udp0

$ns connect $udp0 $sink

$ns at 1.0 "$cbr0 start"

source gsmlink.tcl

proc finish {} {
    global ns nf tf
    $ns flush-trace
    exec nam 5.nam &
    close $nf
    close $tf
    exit 0
}

$ns at 250 "finish"
$ns run