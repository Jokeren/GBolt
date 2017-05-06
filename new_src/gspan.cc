#include <common.h>
#include <config.h>
#include <database.h>
#include <gspan.h>
#include <gflags/gflags.h>

DEFINE_string(input_file, "", "Input path of graph data");
DEFINE_string(output_file, "", "Output gspan mining results");
DEFINE_double(support, 1.0, "Minimum subgraph frequency");
DEFINE_string(separator, " ", "Graph data separator");

// Initialize instance
using gspan::Database;
Database *Database::instance_ = new Database();

int main(int argc, char *argv[]) {
  std::string version_string = GSPAN_VERSION_MAJOR + "." + GSPAN_VERSION_MINOR;
  gflags::SetVersionString(version_string);
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  if (FLAGS_support > 1.0 || FLAGS_support <= 0.0) {
    LOG(FATAL) << "Support must be less than 1.0 and greater than 0.0";
  }
  // Read input
  Database::get_instance()->read_input(FLAGS_input_file, FLAGS_separator);
  // Construct algorithm
	gspan::GSpan gspan(FLAGS_output_file, FLAGS_support);
  gspan.execute();
  return 0;
}
