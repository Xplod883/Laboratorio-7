# Laboratorio 7

Objetivo: Desarrollar una clase en C++ llamada CuentaBancaria, aplicando condicionales (if-else, switch-case) para simular operaciones bancarias. Se busca que los estudiantes integren al menos 5 condiciones en la lógica de la clase sin el uso de arreglos, vectores o punteros.

Instrucciones
1. Creación de la clase CuentaBancaria con los siguientes atributos:
  o string titular
  o double saldo
  o bool activa
  o int intentosFallidos
2. Implementar los siguientes métodos:
  o depositar(double monto): Aumenta el saldo si la cuenta está activa.
  o retirar(double monto): Disminuye el saldo si hay fondos suficientes.
  o consultarSaldo(): Muestra el estado de la cuenta.
3. Condiciones a incluir (Elijan 5 mínimo de las siguientes o creen sus propias reglas):
  o No se puede retirar más dinero del saldo disponible.
  o Si el saldo cae por debajo de 100, mostrar una advertencia.
  o Si hay 3 intentos fallidos de retiro, la cuenta se bloquea.
  o No se pueden hacer depósitos si la cuenta está bloqueada.
  o No se pueden hacer retiros si la cuenta está bloqueada.
(simular con una variable mesesInactivo).
4. Estructura del programa:
  o Implementar la clase CuentaBancaria.
  o Crear un menú interactivo con switch-case que permita al usuario:
    1. Depositar
    2. Retirar
    3. Consultar saldo
    4. Salir
  o Probar diferentes escenarios para asegurarse de que las condiciones funcionan correctamente.
