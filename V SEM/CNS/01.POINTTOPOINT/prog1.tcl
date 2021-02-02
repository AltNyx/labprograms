# Initialization

# create a ns simulator
set ns [new Simulator]

# open the ns trace file
set tracefile [open prog1.tr w]

# All traces are written in the tracefile
$ns trace-all $tracefile

# open the nam trace file
set namfile [open prog1.nam w]

# All nam traces are written in to the namtracefile
$ns namtrace-all $namfile

# Create nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]

# define different colors for different flows
$ns color 1 blue
$ns color 2 red

# providing labels to the nodes
$n0 label "Source/udp0"
$n1 label "Source/udp1"
$n2 label "router"
$n3 label "destination/Null"

# create links between nodes
# $ns duplex-link node1 node2 bandwidth delay queue-type
$ns duplex-link $n0 $n2 10Mb 300ms DropTail
$ns duplex-link $n1 $n2 10Mb 300ms DropTail
$ns duplex-link $n2 $n3 1Mb 300ms DropTail

# Set the queue size
$ns queue-limit $n0 $n2 10
$ns queue-limit $n1 $n2 10
$ns queue-limit $n2 $n3 5

# Attach an udp agent to nodes n0 and n1 and null agent to n3
set udp0 [new Agent/UDP]
$ns attach-agent $n0 $udp0
set cbr0 [new Application/Traffic/CBR]
$cbr0 attach-agent $udp0

set null3 [new Agent/Null]
$ns attach-agent $n3 $null3

set udp1 [new Agent/UDP]
$ns attach-agent $n1 $udp1
set cbr1 [new Application/Traffic/CBR]
$cbr1 attach-agent $udp1

# set red color to udp0 packets and blue color udp1 packets
$udp0 set class_ 1
$udp1 set class_ 2

# connect the agents
$ns connect $udp0 $null3
$ns connect $udp1 $null3

# set packet size to 500
$cbr1 set packetSize_ 500

# set interval for the packets
$cbr1 set interval_ 0.005

# define a finish procedure
proc finish {} {
    global ns tracefile namfile
    $ns flush-trace
    exec nam prog1.nam &
    close $tracefile
    close $namfile
    exit 0
}

$ns at 0.1 "$cbr0 start"
$ns at 0.1 "$cbr1 start"
$ns at 5.0 "finish"
$ns run