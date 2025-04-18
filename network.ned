channel PipelinedChannel extends ned.DatarateChannel
{
    @class(PipelinedChannel);
}
simple Global {
    parameters:
        int n;
        int m;
        int B;
        int Bm;
        int D;
        int F;
        int L;
        int dtSize;
        int numBatch;
        object subserverDelay;
        object subserverBandwidth;
}

simple Subserver {
    parameters:
        int id;
        double C;
    gates:
        input globalIn[8];
        output globalOut[8];
        input localIn[5];
        output localOut[5];
}

simple Client {
    parameters:
        int id;
    gates:
        input in;
        output out;
}

network Network {
    submodules:
        global: Global { @display("i=block/control;p=50,50");
             n = 8;
             m = 5;
             B = 1000000;
             Bm = 50000;
             D = 16384;
             F = 53248;
             L = 126;
             dtSize = 4;
             numBatch = 1000;
             subserverDelay = [
                [0, 67.0, 49.0, 96.0, 124.0, 136.0, 143.0, 124.0],
                [67.0, 0, 11.0, 143.0, 172.0, 76.0, 90.0, 67.0],
                [49.0, 11.0, 0, 130.0, 159.0, 86.0, 99.0, 77.0],
                [96.0, 143.0, 130.0, 0, 34.0, 210.0, 235.0, 199.0],
                [124.0, 172.0, 159.0, 34.0, 0, 238.0, 235.0, 228.0],
                [136.0, 76.0, 86.0, 210.0, 238.0, 0, 14.0, 12.0],
                [143.0, 90.0, 99.0, 235.0, 235.0, 14.0, 0, 24.0],
                [124.0, 67.0, 77.0, 199.0, 228.0, 12.0, 24.0, 0]
            ];
             subserverBandwidth = [
                [0, 1.15, 1.1, 0.523, 0.46, 0.42, 0.404, 0.482],
                [1.15, 0, 1.12, 0.524, 0.5, 0.364, 1.02, 1.05],
                [1.1, 1.12, 0, 0.694, 0.529, 1.05, 0.799, 1.14],
                [0.523, 0.524, 0.694, 0, 1.1, 0.366, 0.36, 0.465],
                [0.46, 0.5, 0.529, 1.1, 0, 0.342, 0.358, 0.335],
                [0.42, 0.364, 1.05, 0.366, 0.342, 0, 1.14, 1.09],
                [0.404, 1.02, 0.799, 0.36, 0.358, 1.14, 0, 1.08],
                [0.482, 1.05, 1.14, 0.465, 0.335, 1.09, 1.08, 0]
            ];
        }
        Oregon: Subserver { id = 0; C = 1e18; @display("p=590,370"); }
        Virginia: Subserver { id = 1; C = 2e18; @display("p=525,525"); }
        Ohio: Subserver { id = 2; C = 3e18; @display("p=370,590"); }
        Tokyo: Subserver { id = 3; C = 4e18; @display("p=214,525"); }
        Seoul: Subserver { id = 4; C = 5e18; @display("p=150,370"); }
        London: Subserver { id = 5; C = 6e18; @display("p=214,214"); }
        Frankfurt: Subserver { id = 6; C = 7e18; @display("p=369,150"); }
        Ireland: Subserver { id = 7; C = 8e18; @display("p=525,214"); }
        OregonC0: Client { id = 0; @display("p=674,285"); }
        OregonC1: Client { id = 1; @display("p=700,324"); }
        OregonC2: Client { id = 2; @display("p=710,370"); }
        OregonC3: Client { id = 3; @display("p=700,415"); }
        OregonC4: Client { id = 4; @display("p=674,454"); }
        VirginiaC0: Client { id = 0; @display("p=645,525"); }
        VirginiaC1: Client { id = 1; @display("p=636,571"); }
        VirginiaC2: Client { id = 2; @display("p=610,610"); }
        VirginiaC3: Client { id = 3; @display("p=571,636"); }
        VirginiaC4: Client { id = 4; @display("p=525,645"); }
        OhioC0: Client { id = 0; @display("p=454,674"); }
        OhioC1: Client { id = 1; @display("p=415,700"); }
        OhioC2: Client { id = 2; @display("p=370,710"); }
        OhioC3: Client { id = 3; @display("p=324,700"); }
        OhioC4: Client { id = 4; @display("p=285,674"); }
        TokyoC0: Client { id = 0; @display("p=214,645"); }
        TokyoC1: Client { id = 1; @display("p=168,636"); }
        TokyoC2: Client { id = 2; @display("p=129,610"); }
        TokyoC3: Client { id = 3; @display("p=103,571"); }
        TokyoC4: Client { id = 4; @display("p=94,525"); }
        SeoulC0: Client { id = 0; @display("p=65,454"); }
        SeoulC1: Client { id = 1; @display("p=39,415"); }
        SeoulC2: Client { id = 2; @display("p=30,370"); }
        SeoulC3: Client { id = 3; @display("p=39,324"); }
        SeoulC4: Client { id = 4; @display("p=65,285"); }
        LondonC0: Client { id = 0; @display("p=94,214"); }
        LondonC1: Client { id = 1; @display("p=103,168"); }
        LondonC2: Client { id = 2; @display("p=129,129"); }
        LondonC3: Client { id = 3; @display("p=168,103"); }
        LondonC4: Client { id = 4; @display("p=214,94"); }
        FrankfurtC0: Client { id = 0; @display("p=285,65"); }
        FrankfurtC1: Client { id = 1; @display("p=324,39"); }
        FrankfurtC2: Client { id = 2; @display("p=369,30"); }
        FrankfurtC3: Client { id = 3; @display("p=415,39"); }
        FrankfurtC4: Client { id = 4; @display("p=454,65"); }
        IrelandC0: Client { id = 0; @display("p=525,94"); }
        IrelandC1: Client { id = 1; @display("p=571,103"); }
        IrelandC2: Client { id = 2; @display("p=610,129"); }
        IrelandC3: Client { id = 3; @display("p=636,168"); }
        IrelandC4: Client { id = 4; @display("p=645,214"); }
    connections allowunconnected:
        Oregon.globalOut[1] --> PipelinedChannel { delay = 67ms; datarate = 1.15Gbps; } --> Virginia.globalIn[0];
        Oregon.globalOut[2] --> PipelinedChannel { delay = 49ms; datarate = 1.10Gbps; } --> Ohio.globalIn[0];
        Oregon.globalOut[3] --> PipelinedChannel { delay = 96ms; datarate = 0.523Gbps; } --> Tokyo.globalIn[0];
        Oregon.globalOut[4] --> PipelinedChannel { delay = 124ms; datarate = 0.46Gbps; } --> Seoul.globalIn[0];
        Oregon.globalOut[5] --> PipelinedChannel { delay = 136ms; datarate = 0.42Gbps; } --> London.globalIn[0];
        Oregon.globalOut[6] --> PipelinedChannel { delay = 143ms; datarate = 0.404Gbps; } --> Frankfurt.globalIn[0];
        Oregon.globalOut[7] --> PipelinedChannel { delay = 124ms; datarate = 0.482Gbps; } --> Ireland.globalIn[0];
        Virginia.globalOut[0] --> PipelinedChannel { delay = 67ms; datarate = 1.15Gbps; } --> Oregon.globalIn[1];
        Virginia.globalOut[2] --> PipelinedChannel { delay = 11ms; datarate = 1.12Gbps; } --> Ohio.globalIn[1];
        Virginia.globalOut[3] --> PipelinedChannel { delay = 143ms; datarate = 0.524Gbps; } --> Tokyo.globalIn[1];
        Virginia.globalOut[4] --> PipelinedChannel { delay = 172ms; datarate = 0.500Gbps; } --> Seoul.globalIn[1];
        Virginia.globalOut[5] --> PipelinedChannel { delay = 76ms; datarate = 0.364Gbps; } --> London.globalIn[1];
        Virginia.globalOut[6] --> PipelinedChannel { delay = 90ms; datarate = 1.02Gbps; } --> Frankfurt.globalIn[1];
        Virginia.globalOut[7] --> PipelinedChannel { delay = 67ms; datarate = 1.05Gbps; } --> Ireland.globalIn[1];
        Ohio.globalOut[0] --> PipelinedChannel { delay = 49ms; datarate = 1.10Gbps; } --> Oregon.globalIn[2];
        Ohio.globalOut[1] --> PipelinedChannel { delay = 11ms; datarate = 1.12Gbps; } --> Virginia.globalIn[2];
        Ohio.globalOut[3] --> PipelinedChannel { delay = 130ms; datarate = 0.694Gbps; } --> Tokyo.globalIn[2];
        Ohio.globalOut[4] --> PipelinedChannel { delay = 159ms; datarate = 0.529Gbps; } --> Seoul.globalIn[2];
        Ohio.globalOut[5] --> PipelinedChannel { delay = 86ms; datarate = 1.05Gbps; } --> London.globalIn[2];
        Ohio.globalOut[6] --> PipelinedChannel { delay = 99ms; datarate = 0.799Gbps; } --> Frankfurt.globalIn[2];
        Ohio.globalOut[7] --> PipelinedChannel { delay = 77ms; datarate = 1.14Gbps; } --> Ireland.globalIn[2];
        Tokyo.globalOut[0] --> PipelinedChannel { delay = 96ms; datarate = 0.523Gbps; } --> Oregon.globalIn[3];
        Tokyo.globalOut[1] --> PipelinedChannel { delay = 143ms; datarate = 0.524Gbps; } --> Virginia.globalIn[3];
        Tokyo.globalOut[2] --> PipelinedChannel { delay = 130ms; datarate = 0.694Gbps; } --> Ohio.globalIn[3];
        Tokyo.globalOut[4] --> PipelinedChannel { delay = 34ms; datarate = 1.1Gbps; } --> Seoul.globalIn[3];
        Tokyo.globalOut[5] --> PipelinedChannel { delay = 210ms; datarate = 0.366Gbps; } --> London.globalIn[3];
        Tokyo.globalOut[6] --> PipelinedChannel { delay = 235ms; datarate = 0.36Gbps; } --> Frankfurt.globalIn[3];
        Tokyo.globalOut[7] --> PipelinedChannel { delay = 199ms; datarate = 0.465Gbps; } --> Ireland.globalIn[3];
        Seoul.globalOut[0] --> PipelinedChannel { delay = 124ms; datarate = 0.46Gbps; } --> Oregon.globalIn[4];
        Seoul.globalOut[1] --> PipelinedChannel { delay = 172ms; datarate = 0.500Gbps; } --> Virginia.globalIn[4];
        Seoul.globalOut[2] --> PipelinedChannel { delay = 159ms; datarate = 0.529Gbps; } --> Ohio.globalIn[4];
        Seoul.globalOut[3] --> PipelinedChannel { delay = 34ms; datarate = 1.1Gbps; } --> Tokyo.globalIn[4];
        Seoul.globalOut[5] --> PipelinedChannel { delay = 238ms; datarate = 0.342Gbps; } --> London.globalIn[4];
        Seoul.globalOut[6] --> PipelinedChannel { delay = 235ms; datarate = 0.358Gbps; } --> Frankfurt.globalIn[4];
        Seoul.globalOut[7] --> PipelinedChannel { delay = 228ms; datarate = 0.335Gbps; } --> Ireland.globalIn[4];
        London.globalOut[0] --> PipelinedChannel { delay = 136ms; datarate = 0.42Gbps; } --> Oregon.globalIn[5];
        London.globalOut[1] --> PipelinedChannel { delay = 76ms; datarate = 0.364Gbps; } --> Virginia.globalIn[5];
        London.globalOut[2] --> PipelinedChannel { delay = 86ms; datarate = 1.05Gbps; } --> Ohio.globalIn[5];
        London.globalOut[3] --> PipelinedChannel { delay = 210ms; datarate = 0.366Gbps; } --> Tokyo.globalIn[5];
        London.globalOut[4] --> PipelinedChannel { delay = 238ms; datarate = 0.342Gbps; } --> Seoul.globalIn[5];
        London.globalOut[6] --> PipelinedChannel { delay = 14ms; datarate = 1.14Gbps; } --> Frankfurt.globalIn[5];
        London.globalOut[7] --> PipelinedChannel { delay = 12ms; datarate = 1.09Gbps; } --> Ireland.globalIn[5];
        Frankfurt.globalOut[0] --> PipelinedChannel { delay = 143ms; datarate = 0.404Gbps; } --> Oregon.globalIn[6];
        Frankfurt.globalOut[1] --> PipelinedChannel { delay = 90ms; datarate = 1.02Gbps; } --> Virginia.globalIn[6];
        Frankfurt.globalOut[2] --> PipelinedChannel { delay = 99ms; datarate = 0.799Gbps; } --> Ohio.globalIn[6];
        Frankfurt.globalOut[3] --> PipelinedChannel { delay = 235ms; datarate = 0.36Gbps; } --> Tokyo.globalIn[6];
        Frankfurt.globalOut[4] --> PipelinedChannel { delay = 235ms; datarate = 0.358Gbps; } --> Seoul.globalIn[6];
        Frankfurt.globalOut[5] --> PipelinedChannel { delay = 14ms; datarate = 1.14Gbps; } --> London.globalIn[6];
        Frankfurt.globalOut[7] --> PipelinedChannel { delay = 24ms; datarate = 1.08Gbps; } --> Ireland.globalIn[6];
        Ireland.globalOut[0] --> PipelinedChannel { delay = 124ms; datarate = 0.482Gbps; } --> Oregon.globalIn[7];
        Ireland.globalOut[1] --> PipelinedChannel { delay = 67ms; datarate = 1.05Gbps; } --> Virginia.globalIn[7];
        Ireland.globalOut[2] --> PipelinedChannel { delay = 77ms; datarate = 1.14Gbps; } --> Ohio.globalIn[7];
        Ireland.globalOut[3] --> PipelinedChannel { delay = 199ms; datarate = 0.465Gbps; } --> Tokyo.globalIn[7];
        Ireland.globalOut[4] --> PipelinedChannel { delay = 228ms; datarate = 0.335Gbps; } --> Seoul.globalIn[7];
        Ireland.globalOut[5] --> PipelinedChannel { delay = 12ms; datarate = 1.09Gbps; } --> London.globalIn[7];
        Ireland.globalOut[6] --> PipelinedChannel { delay = 24ms; datarate = 1.08Gbps; } --> Frankfurt.globalIn[7];
        OregonC0.out --> PipelinedChannel { delay = 13ms; datarate = 40.55Mbps; } --> Oregon.localIn[0];
        Oregon.localOut[0] --> PipelinedChannel { delay = 13ms; datarate = 279.93Mbps; } --> OregonC0.in;
        OregonC1.out --> PipelinedChannel { delay = 13ms; datarate = 40.55Mbps; } --> Oregon.localIn[1];
        Oregon.localOut[1] --> PipelinedChannel { delay = 13ms; datarate = 279.93Mbps; } --> OregonC1.in;
        OregonC2.out --> PipelinedChannel { delay = 13ms; datarate = 40.55Mbps; } --> Oregon.localIn[2];
        Oregon.localOut[2] --> PipelinedChannel { delay = 13ms; datarate = 279.93Mbps; } --> OregonC2.in;
        OregonC3.out --> PipelinedChannel { delay = 13ms; datarate = 40.55Mbps; } --> Oregon.localIn[3];
        Oregon.localOut[3] --> PipelinedChannel { delay = 13ms; datarate = 279.93Mbps; } --> OregonC3.in;
        OregonC4.out --> PipelinedChannel { delay = 13ms; datarate = 40.55Mbps; } --> Oregon.localIn[4];
        Oregon.localOut[4] --> PipelinedChannel { delay = 13ms; datarate = 279.93Mbps; } --> OregonC4.in;
        VirginiaC0.out --> PipelinedChannel { delay = 13ms; datarate = 40.55Mbps; } --> Virginia.localIn[0];
        Virginia.localOut[0] --> PipelinedChannel { delay = 13ms; datarate = 279.93Mbps; } --> VirginiaC0.in;
        VirginiaC1.out --> PipelinedChannel { delay = 13ms; datarate = 40.55Mbps; } --> Virginia.localIn[1];
        Virginia.localOut[1] --> PipelinedChannel { delay = 13ms; datarate = 279.93Mbps; } --> VirginiaC1.in;
        VirginiaC2.out --> PipelinedChannel { delay = 13ms; datarate = 40.55Mbps; } --> Virginia.localIn[2];
        Virginia.localOut[2] --> PipelinedChannel { delay = 13ms; datarate = 279.93Mbps; } --> VirginiaC2.in;
        VirginiaC3.out --> PipelinedChannel { delay = 13ms; datarate = 40.55Mbps; } --> Virginia.localIn[3];
        Virginia.localOut[3] --> PipelinedChannel { delay = 13ms; datarate = 279.93Mbps; } --> VirginiaC3.in;
        VirginiaC4.out --> PipelinedChannel { delay = 13ms; datarate = 40.55Mbps; } --> Virginia.localIn[4];
        Virginia.localOut[4] --> PipelinedChannel { delay = 13ms; datarate = 279.93Mbps; } --> VirginiaC4.in;
        OhioC0.out --> PipelinedChannel { delay = 13ms; datarate = 40.55Mbps; } --> Ohio.localIn[0];
        Ohio.localOut[0] --> PipelinedChannel { delay = 13ms; datarate = 279.93Mbps; } --> OhioC0.in;
        OhioC1.out --> PipelinedChannel { delay = 13ms; datarate = 40.55Mbps; } --> Ohio.localIn[1];
        Ohio.localOut[1] --> PipelinedChannel { delay = 13ms; datarate = 279.93Mbps; } --> OhioC1.in;
        OhioC2.out --> PipelinedChannel { delay = 13ms; datarate = 40.55Mbps; } --> Ohio.localIn[2];
        Ohio.localOut[2] --> PipelinedChannel { delay = 13ms; datarate = 279.93Mbps; } --> OhioC2.in;
        OhioC3.out --> PipelinedChannel { delay = 13ms; datarate = 40.55Mbps; } --> Ohio.localIn[3];
        Ohio.localOut[3] --> PipelinedChannel { delay = 13ms; datarate = 279.93Mbps; } --> OhioC3.in;
        OhioC4.out --> PipelinedChannel { delay = 13ms; datarate = 40.55Mbps; } --> Ohio.localIn[4];
        Ohio.localOut[4] --> PipelinedChannel { delay = 13ms; datarate = 279.93Mbps; } --> OhioC4.in;
        TokyoC0.out --> PipelinedChannel { delay = 12ms; datarate = 133.15Mbps; } --> Tokyo.localIn[0];
        Tokyo.localOut[0] --> PipelinedChannel { delay = 12ms; datarate = 217.11Mbps; } --> TokyoC0.in;
        TokyoC1.out --> PipelinedChannel { delay = 12ms; datarate = 133.15Mbps; } --> Tokyo.localIn[1];
        Tokyo.localOut[1] --> PipelinedChannel { delay = 12ms; datarate = 217.11Mbps; } --> TokyoC1.in;
        TokyoC2.out --> PipelinedChannel { delay = 12ms; datarate = 133.15Mbps; } --> Tokyo.localIn[2];
        Tokyo.localOut[2] --> PipelinedChannel { delay = 12ms; datarate = 217.11Mbps; } --> TokyoC2.in;
        TokyoC3.out --> PipelinedChannel { delay = 12ms; datarate = 133.15Mbps; } --> Tokyo.localIn[3];
        Tokyo.localOut[3] --> PipelinedChannel { delay = 12ms; datarate = 217.11Mbps; } --> TokyoC3.in;
        TokyoC4.out --> PipelinedChannel { delay = 12ms; datarate = 133.15Mbps; } --> Tokyo.localIn[4];
        Tokyo.localOut[4] --> PipelinedChannel { delay = 12ms; datarate = 217.11Mbps; } --> TokyoC4.in;
        SeoulC0.out --> PipelinedChannel { delay = 6ms; datarate = 148.61Mbps; } --> Seoul.localIn[0];
        Seoul.localOut[0] --> PipelinedChannel { delay = 6ms; datarate = 199.34Mbps; } --> SeoulC0.in;
        SeoulC1.out --> PipelinedChannel { delay = 6ms; datarate = 148.61Mbps; } --> Seoul.localIn[1];
        Seoul.localOut[1] --> PipelinedChannel { delay = 6ms; datarate = 199.34Mbps; } --> SeoulC1.in;
        SeoulC2.out --> PipelinedChannel { delay = 6ms; datarate = 148.61Mbps; } --> Seoul.localIn[2];
        Seoul.localOut[2] --> PipelinedChannel { delay = 6ms; datarate = 199.34Mbps; } --> SeoulC2.in;
        SeoulC3.out --> PipelinedChannel { delay = 6ms; datarate = 148.61Mbps; } --> Seoul.localIn[3];
        Seoul.localOut[3] --> PipelinedChannel { delay = 6ms; datarate = 199.34Mbps; } --> SeoulC3.in;
        SeoulC4.out --> PipelinedChannel { delay = 6ms; datarate = 148.61Mbps; } --> Seoul.localIn[4];
        Seoul.localOut[4] --> PipelinedChannel { delay = 6ms; datarate = 199.34Mbps; } --> SeoulC4.in;
        LondonC0.out --> PipelinedChannel { delay = 12ms; datarate = 35.93Mbps; } --> London.localIn[0];
        London.localOut[0] --> PipelinedChannel { delay = 12ms; datarate = 135.66Mbps; } --> LondonC0.in;
        LondonC1.out --> PipelinedChannel { delay = 12ms; datarate = 35.93Mbps; } --> London.localIn[1];
        London.localOut[1] --> PipelinedChannel { delay = 12ms; datarate = 135.66Mbps; } --> LondonC1.in;
        LondonC2.out --> PipelinedChannel { delay = 12ms; datarate = 35.93Mbps; } --> London.localIn[2];
        London.localOut[2] --> PipelinedChannel { delay = 12ms; datarate = 135.66Mbps; } --> LondonC2.in;
        LondonC3.out --> PipelinedChannel { delay = 12ms; datarate = 35.93Mbps; } --> London.localIn[3];
        London.localOut[3] --> PipelinedChannel { delay = 12ms; datarate = 135.66Mbps; } --> LondonC3.in;
        LondonC4.out --> PipelinedChannel { delay = 12ms; datarate = 35.93Mbps; } --> London.localIn[4];
        London.localOut[4] --> PipelinedChannel { delay = 12ms; datarate = 135.66Mbps; } --> LondonC4.in;
        FrankfurtC0.out --> PipelinedChannel { delay = 12ms; datarate = 34.49Mbps; } --> Frankfurt.localIn[0];
        Frankfurt.localOut[0] --> PipelinedChannel { delay = 12ms; datarate = 96.33Mbps; } --> FrankfurtC0.in;
        FrankfurtC1.out --> PipelinedChannel { delay = 12ms; datarate = 34.49Mbps; } --> Frankfurt.localIn[1];
        Frankfurt.localOut[1] --> PipelinedChannel { delay = 12ms; datarate = 96.33Mbps; } --> FrankfurtC1.in;
        FrankfurtC2.out --> PipelinedChannel { delay = 12ms; datarate = 34.49Mbps; } --> Frankfurt.localIn[2];
        Frankfurt.localOut[2] --> PipelinedChannel { delay = 12ms; datarate = 96.33Mbps; } --> FrankfurtC2.in;
        FrankfurtC3.out --> PipelinedChannel { delay = 12ms; datarate = 34.49Mbps; } --> Frankfurt.localIn[3];
        Frankfurt.localOut[3] --> PipelinedChannel { delay = 12ms; datarate = 96.33Mbps; } --> FrankfurtC3.in;
        FrankfurtC4.out --> PipelinedChannel { delay = 12ms; datarate = 34.49Mbps; } --> Frankfurt.localIn[4];
        Frankfurt.localOut[4] --> PipelinedChannel { delay = 12ms; datarate = 96.33Mbps; } --> FrankfurtC4.in;
        IrelandC0.out --> PipelinedChannel { delay = 9ms; datarate = 48.89Mbps; } --> Ireland.localIn[0];
        Ireland.localOut[0] --> PipelinedChannel { delay = 9ms; datarate = 148.37Mbps; } --> IrelandC0.in;
        IrelandC1.out --> PipelinedChannel { delay = 9ms; datarate = 48.89Mbps; } --> Ireland.localIn[1];
        Ireland.localOut[1] --> PipelinedChannel { delay = 9ms; datarate = 148.37Mbps; } --> IrelandC1.in;
        IrelandC2.out --> PipelinedChannel { delay = 9ms; datarate = 48.89Mbps; } --> Ireland.localIn[2];
        Ireland.localOut[2] --> PipelinedChannel { delay = 9ms; datarate = 148.37Mbps; } --> IrelandC2.in;
        IrelandC3.out --> PipelinedChannel { delay = 9ms; datarate = 48.89Mbps; } --> Ireland.localIn[3];
        Ireland.localOut[3] --> PipelinedChannel { delay = 9ms; datarate = 148.37Mbps; } --> IrelandC3.in;
        IrelandC4.out --> PipelinedChannel { delay = 9ms; datarate = 48.89Mbps; } --> Ireland.localIn[4];
        Ireland.localOut[4] --> PipelinedChannel { delay = 9ms; datarate = 148.37Mbps; } --> IrelandC4.in;
}