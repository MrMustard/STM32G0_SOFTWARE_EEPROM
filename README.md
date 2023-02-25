# STM32G0_SOFTWARE_EEPROM
SOFTWARE EEPROM USING XCUBE STM32 


Nota: dentro del main.c se deben de crear como varaibles globales
las siguentes varibales:

```
uint32_t hexPage;//esta varaible si es indispensable
uint32_t readData;//esta varaible no es necesaria, solo es ara guardar los datos recibidos de varaibles eneteras

````


dentro del main antes de que inicie el while infinito debemos de inicializar la varaibles hexPage

```

hexPage = getHexAddressPage(DATA_PAGE);            //Get our hex page // nos devuelve los dat
````


Ya todo esta preparado para que solo uses las funciones de guardar lista blanca
y leer permisos y list telefonica

no hay pierde

