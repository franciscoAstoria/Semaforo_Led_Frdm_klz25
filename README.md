# Perguntas:

#### Por que os LEDs são Active Low (acendem quando se coloca 0 na saída)?

  A construção dos pinos do microcontrolador funcionam de forma que os leds estejam sempre recebendo alimentação de um lado e o outro esteja conectado ao pino, portanto, quando o pino também está em high acaba não existindo ddp, logo o led não liga. Seguindo a mesma lógica, quando o pino está em 0 ele liga, porque existe diferença de potencial entre os pólos do led.

#### Quais funções você usou para acender e apagar os LEDs?

  Utilizei inicialmente a função gpio_pin_toggle() que invertia o sinal dos pinos, mas depois utilizei o gpio_pin_set_dt() que eu escolhia exatamente o que eu queria em cada pino.

#### Explique o que é o DeviceTree.

  O DeviceTree é uma abstração do hardware do microcontrolador, descrevendo sua estrutura, como endereços de memória, portas, timers e periféricos em geral. Dessa forma, esses componentes podem ser acessados pelo código de maneira mais simples, facilitando o desenvolvimento, aumentando a legibilidade e evitando que o programador precise acessar diretamente cada endereço de memória ou consultar o manual do microcontrolador a todo momento, aumentando a eficiência do desenvolvimento.

#### Explique as abstrações feitas pelo Sistema Operacional.

  O sistema operacional faz abstrações para facilitar o uso do hardware pelo programador. Em vez de precisar configurar manualmente registradores, endereços de memória e periféricos diretamente no microcontrolador, podemos utilizar funções prontas fornecidas pelo sistema. No Zephyr, por exemplo, usamos funções como gpio_pin_set_dt() e k_msleep() sem precisar acessar diretamente os registradores internos do GPIO ou do timer. Isso deixa o código mais simples, organizado e fácil de entender, além de aumentar a portabilidade entre diferentes placas e microcontroladores.

