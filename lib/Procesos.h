#include <stdio.h>
#include <string.h>

//Prototipo de funciones
    void showProducts(const char **,const int *,int, int);
    void addBasket(int *);
    void showBasket(const char **,const int *,int *);
    int removeBasket(int *, int);
    int getContadorProductos();
    int totalCompra(const int *, int *);
    int buscarArreglo(const int *, int);
    int contadorProductos=0;

    //Muestra la lista de prodcutos
void showProducts(const char **nombreProducto, const int *precioProducto, int categoriaInicio, int categoriaFinal){
    int i;
    for(i=categoriaInicio; i<categoriaFinal;i++)
	{
        printf("\n\t %d) %s:",i+1,nombreProducto[i]);
        printf(" -- $ %d", precioProducto[i]);
    }

    printf("\n\n");
}

    //Añade elentos al carrito de compras
void addBasket(int *agregarCanasta)
{
    scanf("%d", &agregarCanasta[contadorProductos]);
    contadorProductos++;
}

    //Muestra los elementos del carrito de compras
void showBasket(const char **nombreProducto,const int *precioProducto,int *productoAgregado)
{
        int i;
        for(i=0; i<contadorProductos;i++)
        {
        	printf("\t%d. %s - $ %d\n",i+1,nombreProducto[productoAgregado[i]-1], precioProducto[productoAgregado[i]-1]);
		}
}
            
    //Elimina el elemento de la lista 
int removeBasket(int *eliminarDeCanasta, int eliminarCarrito)
{
    int i;
    for(i=0; i<contadorProductos;i++)
	{
        if(i==eliminarCarrito-1)
		{
            while(i<contadorProductos)
			{
                eliminarDeCanasta[i]= eliminarDeCanasta[i+1];
                i++;
            }
        	contadorProductos=contadorProductos-1;
        	return 1;
        }
    }
    return -1;
}


int getContadorProductos()
{
    return contadorProductos;
}

    //Obtiene el precio total de los productos en el arreglo
int totalCompra(const int *precioProducto,int *productoAgregado)
{
    int i,total=0;
    for(i=0; i<getContadorProductos();i++)
	{
        total+= precioProducto[productoAgregado[i]-1];
    }
    return total;
}

int buscarArreglo(const int *codigosPostales, int clave)
{
    int i;
    for(i=0; i<10; i++)
	{
        if(codigosPostales[i]==clave)
        {
        	return 1;
        }
    }
    return -1;         
}
