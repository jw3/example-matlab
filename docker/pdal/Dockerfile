FROM pdal/dependencies

RUN git clone --depth=1 https://github.com/PDAL/PDAL \
    && cd PDAL \
    && git checkout master \
    && mkdir build

RUN apt-get update \
 && apt-get install nano locate \
 && updatedb

WORKDIR /PDAL

COPY build.sh /PDAL/build

CMD ["/PDAL/build.sh"]
