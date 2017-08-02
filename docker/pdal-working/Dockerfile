FROM pdal/dependencies

RUN git clone https://github.com/jw3/PDAL.git --branch matlab-build --single-branch   \
    && cd PDAL \
    && git branch \
    && git checkout matlab-build \
    && mkdir build

RUN apt-get update \
 && apt-get install nano locate \
 && updatedb

ENV PATH="/matlab/bin:$PATH"

WORKDIR /PDAL

COPY build.sh /PDAL/build

CMD ["/PDAL/build.sh"]
