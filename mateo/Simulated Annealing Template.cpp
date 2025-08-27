// si tienes que enviar el codigo efriamiento = 0.999, 0,9999 y T0 = 1e4, T0=1e6 (recomendado)
// se enfria entre 1e-7 y 1e-4. probar 1e-7 
// para problemas con espacios de busquedas grandes (output only) efriamiento = 0,9999 hasta 0.999999 y T0=1e9 // tarda mucho creo
// T0 = 1e9 y enfriamiento 0.999999 T>=1e-6 
// ir escribiendo la respuesta en el archivo si no termina de correr
// si el espacio de busqueda no es tan grande entonces no es necesario hacer 1e9 creo, si no correrlo varias veces
// para optimizar el SA hacerlo en la fucion costo e.g en lugar de O(n*n) -> O(n)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int costo(int estado) {
    return 1;
}

int vecino(int estado) {
    int vec = estado + 1;
    return vec;
}

signed main() {
    fastIO;
    // quiero maximizar la funcion costo
    int estado; // random
    double T = 1e6;
    while (T > 1e-6) {
        int vec = vecino(estado);
        if (costo(vec) > costo(estado)) {
            estado = vec;
        } else {
            int delta = abs(costo(vec) - costo(estado));
            double prob = exp(-delta / T);
            if (prob > uniform_real_distribution<double>(0, 1)(rng)) {
                estado = vec;
            }
        }
        T *= 0.999;
    }
}
