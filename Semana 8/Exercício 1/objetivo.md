# Semana 8 - Aula prática nº 3

**Microcontrolador:** PIC18F45K20

**Objetivos:**
- Descrever o funcionamento do módulo Conversor A/D, dos módulos CCP (Capture, Compare e PWM) e dos seus relacionamentos com o sistema de interrupção de programa do microcontrolador 18F45K20.
- Mostrar como o Timer 2 é usado no controle das funções pertinentes ao módulo CCP2.
- Escrever, depurar, gravar e testar programa em C que permita o tratamento do Conversor A/D e do módulo CCP1 do 18F45k20.

**Métodos:** Ao girar o potenciômetro, o valor da tensão do mesmo deve ser mostrado nos LEDs de forma binária.
- Fazer amostras da tensão presente no potenciômetro RP1 e mostrar, através dos LED1 (menos significativo) até LED6 (mais significativo), a tensão medida no potenciômetro, em binário, com uma aproximação de uma casa decimal. Por exemplo, ao medir uma tensão de 2,34 V, mostrar nos LED o código binário 010 0011 (que será lido como 2,3 V) e, ao medir uma tensão de 3,87 V, mostrar nos LED o código binário 011 1001 (que será lido como 3,9 V).
- De acordo com o valor do potenciômetro, acender o LED7 de acordo com um ciclo de trabalho que varia de um período mínimo a um período máximo de acendimento e que, ao lê a tensão como sendo de 2,5 V, o tempo de acendimento corresponda a um ciclo de trabalho de 50% (no qual o tempo aceso é o mesmo do tempo apagado).