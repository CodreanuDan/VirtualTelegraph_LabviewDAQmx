int i;
int count = 1;
int current = input[0];
int index = 0;

int temp_result[100];     // buffer local intern
int result_out[100];      // output declarat explicit ca array
int result_len = 0;       // lungimea efectiva a vectorului rezultat

for (i = 1; i < input_len; i++) 
{
    if (input[i] == current) 
    {
        count++;
    } 
    else 
    {
        if (current == 45) 
        {  // '-'
            if (count <= 3)
            {
                temp_result[index++] = 1; // punct scurt
            }
            else
            {
                temp_result[index++] = 2; // linie lunga
            }
        } 
        else if (current == 46) 
        { // '.'
            if (count <= 2)
            {
                temp_result[index++] = 0; // pauza scurta
            }
            else if (count <= 6)
            {
                temp_result[index++] = 3; // sfarsit litera
            }
            else
            {
                temp_result[index++] = 4; // sfarsit cuvant
            }
        }
        count = 1;
        current = input[i];
    }
}

// Procesam ultimul grup
if (current == 45) 
{
    if (count <= 3)
    {
        temp_result[index++] = 1;
    }
    else
    {
        temp_result[index++] = 2;
    }
} 
else if (current == 46) 
{
    if (count <= 2)
    {
        temp_result[index++] = 0;
    }
    else if (count <= 6)
    {
        temp_result[index++] = 3;
    }
    else
    {
        temp_result[index++] = 4;
    }
}

// Copiem bufferul in output
for (i = 0; i < index; i++) 
{
    result_out[i] = temp_result[i];
}

// Truncherea: gasim ultimul index cu valoare > 0
int last_index = -1;
for (i = 0; i < index; i++) 
{
    if (result_out[i] > 0) 
    {
        last_index = i;
    }
}

// Setam lungimea rezultatului util
if (last_index >= 0) 
{
    result_len = last_index + 1;
} 
else 
{
    result_len = 0;  // toate valori sunt 0 sau vector gol
}

// Optional: stergem (setam la -1) restul elementelor dupa lungimea utila
for (i = result_len; i < index; i++) 
{
    result_out[i] = -1;
}
