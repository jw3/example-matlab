FROM pdal/dependencies

RUN git clone --depth=1 https://github.com/jw3/example-matlab \
    && cd example-matlab \
    && git checkout master \
    && mkdir build

RUN apt-get update \
 && apt-get install nano locate \
 && updatedb

WORKDIR /example-matlab
