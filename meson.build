project('CBBS', 'c')

compiler = meson.get_compiler('c')


installation = get_option('install_dir')

buildsys_src = [
    './src/error.c',
    './src/buildsys/buildsys.c',
    './src/buildsys/buildfile.c',
    './src/buildsys/cache.c',
]

buildsys_include = include_directories('include')

executable('buildsys', buildsys_src, include_directories: buildsys_include, install: true, install_dir: installation)