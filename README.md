ESP32 Painless Mesh

Hello Guys!! In this Project I have used 4 ESP-32 Modules. 1 ESP-32 Module is equipped with DHT-11 Sensor, it transmits the Temperature and Relative Humidity data
to the other modules in this Painless Network. The other 3 Modules will send "HI" msgs into the network which is received by the other 3 in the network. The Modules can be 
easily differentiated by node addresses.

ESP-MESH allows multiple devices (nodes) to communicate with each other under a single wireless local area network. It is supported on the ESP32 and ESP8266 boards.
![image](https://user-images.githubusercontent.com/97583689/218307598-b8392531-11d8-4bf8-9274-bea824e1e811.png)

Introducing ESP-MESH

Accordingly to the Espressif documentation:

“ESP-MESH is a networking protocol built atop the Wi-Fi protocol. ESP-MESH allows numerous devices (referred to as nodes) spread over a large physical area (both indoors and outdoors) to be interconnected under a single WLAN (Wireless Local-Area Network).
ESP-MESH is self-organizing and self-healing meaning the network can be built and maintained autonomously

Traditional Wi-Fi Network Architecture

In a traditional Wi-Fi network architecture, a single node (access point – usually the router) is connected to all other nodes (stations). Each node can communicate with each other using the access point. However, this is limited to the access point wi-fi coverage. Every station must be in the range to connect directly to the access point. This doesn’t happen with ESP-MESH.
![image](https://user-images.githubusercontent.com/97583689/218307660-8dcba01a-1e4d-4ebe-8342-11c1cc7e76ee.png)

ESP-MESH Network Architecture

With ESP-MESH, the nodes don’t need to connect to a central node. Nodes are responsible for relaying each others transmissions. This allows multiple devices to spread over a large physical area. The Nodes can self-organize and dynamically talk to each other to ensure that the packet reaches its final node destination. If any node is removed from the network, it is able to self-organize to make sure that the packets reach their destination.
![image](https://user-images.githubusercontent.com/97583689/218307683-0f9ae22f-e9cb-47c6-8926-cbfc0c7908ed.png)

PainlessMesh Library

The painlessMesh library allows us to create a mesh network with the ESP8266 or/and ESP32 boards in an easy way.

“PainlessMesh is a true ad-hoc network, meaning that no-planning, central controller, or router is required. Any system of 1 or more nodes will self-organize into fully functional mesh. The maximum size of the mesh is limited (we think) by the amount of memory in the heap that can be allocated to the sub-connections buffer and so should be really quite high.”


