# Sistema Embebido de Monitoreo y Alerta Temprana para Prevención de Desbordamiento de Quebradas
<img src="SISTEMA EMBEBIDO (1).png" alt="Descripción" width="1100"/>

# Descripción del proyecto
Este proyecto consiste en el diseño e implementación de un sistema embebido basado en Arduino capaz de monitorear el nivel del agua y generar alertas tempranas ante posibles riesgos de desbordamiento de quebradas.

El sistema utiliza un sensor de nivel de agua para detectar variaciones en el caudal y, dependiendo de la lectura obtenida, activa diferentes actuadores visuales y sonoros que permiten advertir el nivel de riesgo presente.

Se implementaron distintos estados de alerta:

- VERDE | Estado seguro
- AMARILLO + ALARMA INTERMITENTE | Estado de precaución
- ROJO + ALARMA INTERMITENTE | Estado de riesgo alto
- ROJO + ALARMA CONSTANTE | Estado crítico

Además, el sistema incorpora un filtro exponencial para reducir fluctuaciones y falsas alarmas producidas por ruido en las señales analógicas del sensor.

---

# Problemática abordada

En muchas regiones vulnerables, el incremento repentino del nivel de agua en quebradas puede provocar inundaciones y desbordamientos peligrosos para la población.

En numerosos casos, las personas no cuentan con sistemas de monitoreo accesibles que permitan identificar oportunamente cambios en el comportamiento del agua.

Este proyecto busca ofrecer una solución de bajo costo capaz de generar alertas tempranas mediante señales visuales y auditivas, permitiendo advertir a las personas sobre posibles situaciones de riesgo.

---

# Características principales

- Monitoreo continuo del nivel del agua
- Procesamiento en tiempo real usando Arduino
- Alertas visuales mediante LEDs
- Alertas auditivas mediante buzzer
- Sistema de niveles progresivos de riesgo
- Implementación de filtro exponencial
- Bajo costo de implementación

---

# Componentes utilizados

| Componente | Cantidad |
|---|---|
| Arduino Uno | 1 |
| Sensor de nivel de agua HW-038 | 1 |
| LEDs (verde, amarillo y rojo) | 3 |
| Resistencias 220Ω | 3 |
| Buzzer piezoeléctrico TMB12A05 | 1 |
| Protoboard | 1 |
| Cables jumper | Varios |
| Fuente de alimentación USB | 1 |

---

# Diagrama de conexiones

| Componente | Pin Arduino |
|---|---|
| Sensor HW-038 | A0 |
| LED Verde | 3 |
| LED Amarillo | 4 |
| LED Rojo | 5 |
| Buzzer | 8 |
<img src="Esquemático.png" alt="Descripción" width="500"/>


Todos los LEDs fueron conectados en serie con resistencias de 220Ω para limitar la corriente y proteger los componentes.

---

# Funcionamiento del sistema
<img src="Circuito Físico.jpg" alt="Descripción" width="500"/>
El sensor realiza lecturas continuas del nivel del agua y envía una señal analógica al Arduino.

Posteriormente, el sistema aplica un filtro exponencial para suavizar las fluctuaciones presentes en la señal del sensor.

Dependiendo del valor detectado, el sistema activa diferentes alertas:

| Nivel | Acción |
|---|---|
| Bajo | LED verde encendido |
| Medio | LED amarillo + buzzer intermitente lento |
| Alto | LED rojo + buzzer intermitente rápido |
| Crítico | LED rojo + buzzer continuo |

---

# Código principal

## Definición de pines

```cpp
const int sensorPin = A0;
const int buzzerPin = 8;

const int greenLed = 3;
const int yellowLed = 4;
const int redLed = 5;
```
## Filtro exponencial
```cpp
filteredValue = (alpha * reading) +
                ((1 - alpha) * filteredValue);
```


## Lógica de alertas (abreviada)
```cpp
if(sensorValue < level30) {

  digitalWrite(greenLed, HIGH);

} else if(sensorValue < level50) {

  digitalWrite(yellowLed, HIGH);

} else if(sensorValue < level80) {

  digitalWrite(redLed, HIGH);

} else {

  tone(buzzerPin, 2000);
}
```
# Instrucciones de uso

1. Conectar todos los componentes según el diagrama de conexiones.
2. Abrir el archivo `.ino` en Arduino IDE.
3. Seleccionar la placa Arduino Uno y el puerto correspondiente.
4. Compilar y cargar el código al Arduino.
5. Alimentar el sistema mediante conexión USB.
6. Introducir el sensor en contacto con el agua.
7. Observar las alertas visuales y auditivas dependiendo del nivel detectado.

---

# Resultados obtenidos

Durante las pruebas experimentales se observó que el sistema fue capaz de:

- Detectar variaciones del nivel del agua en tiempo real.
- Activar correctamente los distintos niveles de alerta.
- Diferenciar estados de riesgo mediante señales visuales y auditivas.
- Reducir falsas alarmas gracias al filtro exponencial implementado.

También se identificaron fenómenos de respuesta transitoria y tiempos de estabilización del sensor, especialmente durante cambios bruscos en el nivel del agua.

---

# Posibles mejoras futuras

- Implementar sensores capacitivos o ultrasónicos.
- Agregar comunicación inalámbrica.
- Enviar notificaciones a dispositivos móviles.
- Incorporar alimentación autónoma con baterías.
- Integrar almacenamiento de datos y monitoreo remoto.

---

# Autores

Proyecto desarrollado para Circuitos Digitales.

- Laura Sofía Barrios Sosa
- Gabriela Morales Herrera
- Claudia Lorena Cerquera González
- Rosa Catalina Acuña Ramírez

---
