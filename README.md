# HomeEcoClimate (cliente)

Sistema domótico de control del clima interior de un hogar bajo criterios de ahorro energético. Parte de cliente para microcontrolador ESP8266.

## Entorno de desarrollo

Este proyecto está pensado para ser usado junto con [PlatformIO](https://platformio.org/).

## Configuración del microcontrolador ESP8266

El microcontrolador puede usarse para dos funciones distintas, según cómo se compile el proyecto. En cualquiera de los dos casos, se debe
especificar correctamente el nombre y la contraseña de la red Wi-Fi a la que la placa debe conectarse para poder operar como se espera, a través
de las variables `SSID` y `PSK` en `src/main.cpp`. Para habilitar una u otra modalidad es necesario comentar y descomentar las líneas indicadas
en `src/main.cpp` que llaman a las funciones de _setup_ y _handle_ de cada funcionalidad e importar las cabeceras apropiadas. Más detalles en el
comentario al principio del fichero `src/main.cpp`.

### Con actuadores

El microcontrolador administrará un motor servo con la señal de control conectada al pin D2 para la regulación de la temperatura,
otro motor servo con la señal de control conectada al pin D3 para la regulación del ángulo de apertura de las persianas verticales y un motor
ventilador gestionado por un chip L293D, que está conectado al pin D5 para el control de velocidad, al pin D6 para activar el sentido de avance
y al pin D7 para activar el sentido de retroceso. Este último no se usará puesto que solo se contempla el uso del ventilador en un único sentido.
Las instrucciones las recibirá desde el broker MQTT, el cual debe ser indicado en la variable `mqttServer` en `src/actuators.cpp`.

### Con sensores

En este caso, el microcontrolador se comunicará con un sensor de temperatura y humedad combinado DHT11 con la señal de datos conectada al pin
D1. Aproximadamente cada 10 segundos enviará una lectura de ambos parámetros al servidor que implementa la API REST del sistema mediante una
petición _POST_.

## Arquitectura

El manejo de los dispositivos está mediado por librerías que abstraen su uso a modo de drivers y por interfaces propias que adaptan estos
componentes para el uso específico de este proyecto. Para más detalles, consultar la documentación Doxygen integrada en el propio código fuente.
