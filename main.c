#include <stdio.h>

// räkna ut alla individuella medelvärden som gör det lättare att hitta högsta/lägsta osv senare -
// istället för att "massuträkna" allt.
void calculate_individual_averages(int test_results[5][13], float class_averages[5])
{
    for (int i = 0; i < 5; i++)
    {
        float average = 0;
        for (int j = 0; j < 13; j++)
        {
            average += test_results[i][j];
        }
        class_averages[i] = average / 13;
    }
}

// returnerar hela klassens medelvärde
// gör uträkningen här för att undvika att stöka ner main.
float calculate_class_average(float class_averages[5])
{
    float average = 0;
    for (int i = 0; i < 5; i++)
    {
        average += class_averages[i];
    }

    return average / 5;
}

// returnerar det index som är "kopplat" till högsta medelvärdet
// behöver inte vara funktion men blir lättare att debugga om något går snett.
int find_highest_average_index(float class_averages[5])
{
    // temp variabler som underlättar funktionen
    float highest_avg_index = -1;
    float highest_avg = 0;

    for(int i = 0; i < 5; i++)
    {
        if(class_averages[i] > highest_avg)
        {
            highest_avg = class_averages[i];
            highest_avg_index = i;
        }
    }

    return highest_avg_index;
}

int main()
{
    char names[5][11];
    int test_results[5][13];
    float class_average = 0;
    float class_averages[5];

    // Starta inmatning för namn och poäng
    for(int i = 0; i < 5; i++)
    {
        scanf("%10s", names[i]);
        // eftersom versaler var ett krav/poängsättning så går programmet igenom och kollar om första bokstaven är mellan a och z om den är det måste vi gå tillbaka 32 steg i ASCII
        // för att få den rätta bokstaven fast stor.
        if(names[i][0] >='a' && names[i][0] <='z')
        {
            names[i][0] -= 32;
        }

        // skriv in 13 poäng för personen
        for (int j = 0; j < 13; j++)
        {
            scanf("%d", &test_results[i][j]);
        }
    }

    // beskrivning finns ovanför main.
    calculate_individual_averages(test_results, class_averages);

    // beskrivning finns ovanför main.
    class_average = calculate_class_average(class_averages);

    // räkna ut högsta medelvärde
    int highest_avg_idx = find_highest_average_index(class_averages);

    // skriv ut namnet på personen med högst medelvärde.
    printf("%s\n", names[highest_avg_idx]);

    // hitta personerna som ligger under medelvärdet och skriv ut deras namn.
    for(int i = 0; i < 5; i++)
    {
        if(class_averages[i] < class_average)
        {
            printf("%s\n", names[i]);
        }
    }

    return 0;
}