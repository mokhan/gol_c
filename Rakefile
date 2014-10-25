task :default => :test

task :clean do
  "rm *.out"
end

task :build => :clean do
  sh "gcc gol.c"
end

task :test => :build do
  sh "./a.out"
end
