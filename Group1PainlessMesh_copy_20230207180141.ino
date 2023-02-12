 #include "DHT.h"
#define DHTPIN 4     
#define DHTTYPE DHT11  
DHT dht(DHTPIN, DHTTYPE);
#include "painlessMesh.h"
#include <Arduino_JSON.h>
#define   MESH_PREFIX     "RNTMESH" //name for your MESH
#define   MESH_PASSWORD   "MESHpassword" //password for your MESH
#define   MESH_PORT       5555 //default port
int nodeNumber = 1;
String readings;
Scheduler userScheduler; // to control your personal task
painlessMesh  mesh;
void sendMessage() ; // Prototype so PlatformIO doesn't complain
String getReadings(); // Prototype for sending sensor readings
Task taskSendMessage(TASK_SECOND * 5 , TASK_FOREVER, &sendMessage);
String getReadings () {
  JSONVar jsonReadings;
  jsonReadings["node"] = nodeNumber;
  jsonReadings["temp"] = dht.readTemperature();
  jsonReadings["hum"] = dht.readHumidity();
  readings = JSON.stringify(jsonReadings);
  return readings;
}
void sendMessage () {
  String msg = getReadings();
  mesh.sendBroadcast(msg);
  taskSendMessage.setInterval( random( TASK_SECOND*1, TASK_SECOND*5));
}
void receivedCallback( uint32_t from, String &msg ) {
  Serial.printf("Received from %u msg=%s\n", from, msg.c_str());
  JSONVar myObject = JSON.parse(msg.c_str());
  int node = myObject["node"];
  double temp = myObject["temp"];
  double hum = myObject["hum"];
  Serial.print("Node: ");
  Serial.println(node);
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" C");
  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.println(" %");
}
void newConnectionCallback(uint32_t nodeId) {
  Serial.printf("New Connection, nodeId = %u\n", nodeId);
}
void changedConnectionCallback() {
  Serial.printf("Changed connections\n");
}
void nodeTimeAdjustedCallback(int32_t offset) {
  Serial.printf("Adjusted time %u. Offset = %d\n", mesh.getNodeTime(),offset);
}
void setup() {
  Serial.begin(115200);
   dht.begin();
  mesh.setDebugMsgTypes( ERROR | STARTUP );  // set before init() so that you can see startup messages
  mesh.init( MESH_PREFIX, MESH_PASSWORD, &userScheduler, MESH_PORT );
  mesh.onReceive(&receivedCallback);
  mesh.onNewConnection(&newConnectionCallback);
  mesh.onChangedConnections(&changedConnectionCallback);
  mesh.onNodeTimeAdjusted(&nodeTimeAdjustedCallback);
  userScheduler.addTask(taskSendMessage);
  taskSendMessage.enable();
}
void loop() {
  mesh.update();
}