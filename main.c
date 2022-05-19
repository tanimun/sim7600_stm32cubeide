	char ATcommand [80];

	char* pub = "{\"id\":12,\"info\":\"1110102\"}";
	char* str ="{\"clientKeys1\":\"id\",\"clientKeys2\":\"info\"}";
	char* ptopic= "v1/devices/me/attributes";
	char* topic = "v1/devices/me/attributes/request/1";
	char* stopic = "v1/devices/me/attributes/response/+";
	unsigned int q = strlen(ptopic);
	unsigned int n = strlen(topic);
	unsigned int p = strlen(stopic);
	unsigned int r = 0;
	unsigned int m=0;
	r = strlen(pub);
	m = strlen(str);

 sprintf(ATcommand,"Modem Started...",20);
 HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
 HAL_UART_Receive(&huart1, buffer, 30, 100);
 HAL_Delay(10);
 sprintf(ATcommand,"AT\r\n");
 HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
 HAL_UART_Receive(&huart1, buffer, 30, 100);
 HAL_Delay(1000);
 memset(buffer,0,sizeof(buffer));
 
 sprintf(ATcommand,"AT+CSQ\r\n");
 HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
 HAL_DELAY(100);

sprintf(ATcommand,"AT+CPIN?\r\n");
 HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
 HAL_DELAY(100);

sprintf(ATcommand,"AT+COPS?\r\n");
 HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
 HAL_DELAY(100);

sprintf(ATcommand,"AT+CREG=1\r\n");
 HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
 HAL_DELAY(100);

sprintf(ATcommand,"AT+CREG?\r\n");
 HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
 HAL_DELAY(100);

sprintf(ATcommand,"AT+CGMI\r\n");
 HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
 HAL_DELAY(100);

sprintf(ATcommand,"AT+CNMP=2\r\n");
 HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
 HAL_DELAY(100); 

sprintf(ATcommand,"AT+CMQTTDISC=0,120\r\n");
 HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
 HAL_DELAY(100);  
 
 sprintf(ATcommand,"AT+CMQTTREL\r\n");
 HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
 HAL_DELAY(100); 
 
 sprintf(ATcommand,"AT+CMQTTSTOP\r\n");
 HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
 HAL_DELAY(100); 
 
 sprintf(ATcommand,"AT+CMQTTSTOP\r\n");
 HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
 HAL_DELAY(100); 
 
 sprintf(ATcommand,"AT+CMQTTSTART\r\n");
 HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
 HAL_DELAY(1000); 
 
 sprintf(ATcommand,"AT+CMQTTACCQ=0,\"test\"\r\n");
 HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
 HAL_DELAY(1000); 
 
 sprintf(ATcommand,"AT+CMQTTCONNECT=0,\"tcp://thinkiot.com.bd\",20,1,\"test101\",\"test101\"\r\n ");
 HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
 HAL_DELAY(1000);

sprintf(ATcommand,"AT+CMQTTSUBTOPIC=0,%d,0\r\n",p);
 HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
 HAL_DELAY(1000);
sprintf(ATcommand,stopic);
HAL_DELAY}(1000);

sprintf(ATcommand,"AT+CMQTTCONNECT=0,\"tcp://thinkiot.com.bd\",20,1,\"test101\",\"test101\"\r\n ");
 HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
 HAL_DELAY(100); 
 
 
 while(1)
 {
	/*sprintf(ATcommand,"AT+CMQTTTOPIC=0,%d\r\n",q);
	HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand,1000);
	HAL_DELAY(1000); 
	 
	sprintf(ATcommand,"AT+CMQTTPAYLOAD=0,%d\r\n",r);
	HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand,1000);
	HAL_DELAY(1000); 
	sprint(ATcommand, pub);
	HAL_DELAY(1000);
	 	 

	sprintf(ATcommand,"AT+CMQTTPUB=0,0,60\r\n");
	HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand,1000);
	HAL_DELAY(1000); 	
	
	sprintf(ATcommand,"AT+CMQTTTOPIC=0,%d\r\n",n);
	HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand,1000);
	HAL_DELAY(1000); 
	 */
 
 	sprintf(ATcommand,"AT+CMQTTTOPIC=0,%d\r\n",q); //publish topic
	HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
	HAL_UART_Receive(&huart1, buffer, 100, 100);
	HAL_DELAY(1000); 
	
	sprintf(ATcommand,ptopic); //SET topic 
	HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
	HAL_UART_Receive(&huart1, buffer, 30, 100);
	HAL_DELAY(1000); 
	
	sprintf(ATcommand,"AT+CMQTTPAYLOAD=0,%d\r\n",r); //Set publishing message
	HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
	HAL_UART_Receive(&huart1, buffer, 30, 100);
	HAL_DELAY(1000); 
	
	sprintf(ATcommand,pub); //Set publishing message
	HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
	HAL_UART_Receive(&huart1, buffer, 30, 100);
	HAL_DELAY(1000); 
		
	sprintf(ATcommand,"AT+CMQTTPUB=0,0,60\r\n"); //Send a PUBLISH message to server
	HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
	HAL_UART_Receive(&huart1, buffer, 30, 100);
	HAL_DELAY(1000); 
		
	sprintf(ATcommand,"AT+CMQTTTOPIC=0,%d\r\n",n); //publish topic
	HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
	HAL_UART_Receive(&huart1, buffer, 30, 100);
	HAL_DELAY(1000); 
	
	sprintf(ATcommand,topic); //SET topic 
	HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
	HAL_UART_Receive(&huart1, buffer, 30, 100);
	HAL_DELAY(1000); 
	
	sprintf(ATcommand,"AT+CMQTTPAYLOAD=0,%d\r\n",m); //Set publishing message
	HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
	HAL_UART_Receive(&huart1, buffer, 30, 100);
	HAL_DELAY(1000); 
	
	sprintf(ATcommand,str); //Set publishing message
	HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
	HAL_UART_Receive(&huart1, buffer, 30, 100);
	HAL_DELAY(1000); 
	
	sprintf(ATcommand,"AT+CMQTTPUB=0,0,60\r\n"); //Send a PUBLISH message to server
	HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
	HAL_UART_Receive(&huart1, buffer, 30, 100);
	HAL_DELAY(1000); 
 }
