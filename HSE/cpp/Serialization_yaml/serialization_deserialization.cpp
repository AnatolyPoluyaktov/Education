#include "serialization_deserialization.hpp"
#include <istream>
namespace serial
{
    void serialization( YAML::Node &document,  std::string filename,benchmark::State &state)
    {   state.PauseTiming();
        std::ofstream fout (filename);
        state.ResumeTiming();
        fout << document;
    }

    YAML::Node deserialization( const std::string filename)
    {
        YAML::Node document = YAML::LoadFile(filename);
        return document;
    }

    void fy_serialization(struct fy_document *document, const char *filename, benchmark::State &state) {
        state.PauseTiming();
        FILE *file;
        file = fopen(filename, "wb");
        state.ResumeTiming();
        fy_emit_document_to_fp(document, FYECF_DEFAULT, file);
        state.PauseTiming();
        fclose(file);
        state.ResumeTiming();
    }
     struct fy_document* fy_deserialization( const char *filename) {
        return fy_document_build_from_file(NULL, filename);
    }
    void libyaml_serialization(yaml_document_t* document,std::string filename,benchmark::State &state)
    {   state.PauseTiming();
        FILE* file;
        yaml_emitter_t emitter;
        yaml_emitter_initialize(&emitter);

        file = fopen(filename.c_str(), "w");
        yaml_emitter_set_output_file(&emitter, file);
        state.ResumeTiming();
        yaml_emitter_dump(&emitter,document);
        state.PauseTiming();
        yaml_emitter_close(&emitter);

        fclose(file);
        state.ResumeTiming();
    }
    yaml_document_t libyaml_deserialization(std::string filename,benchmark::State &state)
       {       state.PauseTiming();

               FILE *file;
               yaml_parser_t parser;

               file = fopen(filename.c_str(), "rb");
               yaml_parser_initialize(&parser);
               yaml_parser_set_input_file(&parser, file);
               yaml_document_t document;
                state.ResumeTiming();
               yaml_parser_load(&parser, &document);
               state.PauseTiming();


               yaml_parser_delete(&parser);
               fclose(file);
               state.ResumeTiming();
               return document;
           }
    }
