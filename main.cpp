#include <iostream>
#include <cstdio>

using namespace std;

void movimentar(float variacao, float velocidade) { //Função que simula a movimentação do robô
    printf("Acabei de me movimentar %f radianos a uma velocidade angular de %f radianos por segundo!\n", variacao, velocidade);
}

int main() {
    printf("Olá!\n");
    float velAng, movAng; // Valores obtidos a partir do giroscópio relacionados à velocidade angular atual do giroscópio e a movimentação angular acumulada
    float varTempo = 0.0; // Variação de tempo de leitura do giroscópio é 5 ms
    float outVar, outVel; // Dados enviados para a movimentação do robô, variação angular e velocidade angular
    bool recebendo = true; //Flag que diz se o giroscópio ainda está fazendo alguma leitura
    
    while(recebendo) {
        printf("Insira os dados do sensor (separados por vírgula):\n"); // Aqui, substituirei por uma função que faz a leitura dos dados do sensor propriamente
        scanf("%f, %f", &velAng, &movAng);
        
        /* A partir dos inputs, precisamos transformar os dados em radianos para poder enviar para o robô, representado pela função movimentar();
        Através do datasheet, sabemos que a escala do giroscópio pode ser configurada em 4 opções, cada uma com um fator de sensibilidade diferente
        Assim, podemos converter os valores recebidos do giroscópio para graus/seg ao dividir os dados recebidos pelo fator de sensibilidade
        A velocidade precisa ser convertida para radianos/seg, portanto, basta multiplicar o resultado obtido da divisão anterior por pi/180 */
        
        // Assim, se considerarmos a escala como a opção 0 (FS_SEL = 0) e considerando que os dados recebidos do giroscópio já estão em graus/seg temos:
        outVel = velAng * (3.1415 / 180);
        outVar = outVel * varTempo;

        movimentar(outVar, outVel);
        varTempo += 0.005; // Tempo de leitura do sensor
        // Preciso fazer o loop esperar 0.005 segundos, o tempo de leitura do sensor, para isso, utilizarei uma função que faça essa linha de execução esperar o tempo necessário
        printf("O sensor ainda está fazendo uma leitura? (1 para sim, 0 para não)\n"); // Aqui, substituirei para a função apropriada que detecte se o sensor ainda está fazendo leituras
        scanf("%d", &recebendo);
    }
    
    printf("Até mais!\n");

    return 0;
}
