task :default => :test

task :clean do
  sh "rm -fr bin"
  sh "mkdir -p bin"
end

task :run => :clean do
  sh "gcc -std=c99 -Wall -g src/gol.c src/main.c -o bin/gol"
  sh "./bin/gol"
end

task :test => :clean do
  sh "gcc -std=c99 -Wall -g src/gol.c src/gol_test.c -o bin/gol_test"
  sh "./bin/gol_test"
end

task :spec => :clean do
  sh "gcc -std=c99 -Wall -g src/world.c src/world_test.c -o bin/game_of_life"
  sh "./bin/game_of_life"
end
