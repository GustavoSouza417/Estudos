echo "1º exercício:"                             # mostrar o diretório corrente
    pwd                                          # 
echo "---------------------------------------"   #
                                                 #
                                                 #
                                                 #
echo "2º exercício:"                             # ir para o diretório /etc                
    cd /etc                                      #
echo "---------------------------------------"   #
                                                 #
                                                 #
                                                 #
echo "3º exercício:"                             # voltar para o diretório "home" pressionando três teclas                                        
                                                 # precisa usar TAB
echo "---------------------------------------"   #                                                 
                                                 #
                                                 #
                                                 #                                                 
echo "4º exercício:"                             # ir para o diretório "./boot/grup" pressionando onze teclas
                                                 # precisa usar TAB
echo "---------------------------------------"   #
                                                 #
                                                 #
                                                 #
echo "5º exercício:"                             # ir para um diretório pai do diretório corrente
    cd ..                                        #
echo "---------------------------------------"   #
                                                 #
                                                 #
                                                 #                                                
echo "6º exercício:"                             # ir para o diretório raiz
    cd /                                         #                                           
echo "---------------------------------------"   #
                                                 #
                                                 #
                                                 #
echo "7° exercício:"                             # listar o conteúdo do diretório atual
    ls                                           # 
echo "---------------------------------------"   #
                                                 #
                                                 #
                                                 #
echo "8° exercício:"                             # listar um diretório de forma detalhada
    ls -l                                        #
echo "---------------------------------------"   #
                                                 #
                                                 #
                                                 #
echo "9° exercício:"                             # listar o conteúdo do diretório "etc" enquanto está no diretório "home"
    ls /etc                                      #
echo "---------------------------------------"   #
                                                 #
                                                 #
                                                 #
echo "10° exercício:"                            # listar o conteúdo dos diretórios "bin" e "sbin" enquanto está no diretório "home"
    ls /bin /sbin                                #
echo "---------------------------------------"   #
                                                 #
                                                 #
                                                 #
echo "11° exercício:"                            # listar o conteúdo do diretório "~" enquanto está no diretório "home"
    ls ~                                         #
echo "---------------------------------------"   #
                                                 #
                                                 #
                                                 #
echo "12° exercício:"                            # listar todos os arquivos, incluindo os ocultos, do diretório "home"
    ls -a                                        #
echo "---------------------------------------"   #
                                                 #
                                                 #
                                                 #
echo "13° exercício:"                            # listar o diretório "boot" de forma bem legível
    ls /boot -lh                                 #
echo "---------------------------------------"   #
                                                 #
                                                 #
                                                 #                                                 
echo "14° exercício:"                            # criar o subdiretório "testdir" dentro do diretório "home"
    cd /home                                     #
    sudo mkdir testdir                           #
echo "---------------------------------------"   #
                                                 #
                                                 #
                                                 #
echo "15° exercício:"                            # criar o diretório "newdir" no diretório "etc"
    cd /etc                                      #
    sudo mkdir newdir                            #
echo "---------------------------------------"   #
                                                 #
                                                 #
                                                 #
echo "16° exercício:"                            # criar três diretórios com um único comando                                          
    sudo mkdir -p dir1/dir2/dir3                 #
echo "---------------------------------------"   #
                                                 #
                                                 #
                                                 #
echo "17° exercício:"                            # remover o diretório "testdir"
    cd /home                                     #
    sudo rmdir testdir                           #
echo "---------------------------------------"   #