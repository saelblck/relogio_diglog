# relogio_diglog
um relógio(prototipo) feito com leds controlado por arduino simulando ponteiros de relógio analógico.<br>
simulado no tinkercad.
<br>
<br>
OBS.: por falta do modulo RTC no simulador, o prototipo só processa a parte de exibição das horas e minutos, mas é de facil implementação do moduto RTC.

## componentes
* 12 leds (usei vermelhos)
* 4 resistores 1K
* 3 transistores NPN
* 1 arduino uno
* 1 push button
* varios jumpers

## funcionamento
foi feito uma matriz com os leds com 3 colunas enumeradas de 1-3 e 4 linhas identificadas de A-D, cada transistor controla uma coluna ligando-as ao GND, as bases dos transistores são ligados ao arduino, assim como os resistores ligam o arduino a cada linha da matriz.