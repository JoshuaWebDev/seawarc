# Sea War

## Jogo Batalha Naval em C

Há um tabuleiro de 5x5, ou seja, 25 blocos. Há 3 navios escondidos (um em cada bloco).
O objetivo do jogo é descobrir onde estão estes navios e acertá-los.
A cada tiro dado é dito se você acertou algum navio. Caso tenha errado, é dito quantos navios existem naquela linha e naquela coluna.
O jogo só acaba quando você descobrir e afundar os 3 navios.

### Legenda pro usuário:

~ : água no bloco. Ainda não foi dado tiro.

\* : tiro dado, não há nada ali.

\# : tiro dado, havia um navio ali.

### Como jogar:

A cada rodada, entre com dois números: o número da linha e o número da coluna onde quer dar o tiro.
Depois é só esperar pra ver se acertou, ou a dica.

### Para os programadores C:

O tabuleiro 5x5 é de inteiros. Ele é inicializado com valores '-1'.
A cada tiro ele é atualizado, dependendo se o usuário acertou ou errou. Esses números servirão para exibir '~', '*' ou 'X' para o usuário.
Também servirão para exibir as dicas.

### Legenda do tabuleiro:

-1 : nenhum tiro foi dado naquele bloco (~)

 0 : o tiro foi dado e não havia nada (*)

 1 : o usuário atirou e tinha um navio lá (X)

 ### Compilando na linha de Compilando

 Se vc usa linux ou possui algum emulador de terminal Linux com o compilador gcc instalado no Windows, é só digitar o comando

  | No terminal (Linux)

 ```bash
 gcc -o seawar seawar.c
 ```

 ou

  | No prompt (Windows)

  ```bash
 gcc -o seawar.exe seawar.c
 ```

 Após compilar o código-fonte é só chamar pelo nome dele no terminal/prompt

 | No prompt (Windows)

 ```bash
 seawar.exe
 ```

  | No terminal (Linux)

 ```bash
 ./seawar
 ```